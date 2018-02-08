#include <linux/rwsem.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_read_init(void);
static void __exit down_read_exit(void);
#define EXEC_DOWN_WRITE 1
struct rw_semaphore rwsem;


int __init down_read_init(void)
{
	init_rwsem(&rwsem);
	printk("After init_rwsem, rwsem.count:%ld\n", rwsem.count.counter);
	if( EXEC_DOWN_WRITE)
		{
		down_write(&rwsem);
		printk("Write lock acquired now!");
		}
	
	down_read(&rwsem);
	printk("First down_read, rwsem.count:%ld\n", rwsem.count.counter);
        
	down_read(&rwsem);
	printk("Second down_read, rwsem.count:%ld\n", rwsem.count.counter);
	while(rwsem.count.counter!=0)
		{
			up_read(&rwsem);
		}	

	return 0;
}

void __exit down_read_exit(void)
{
	printk("exit!\n");
}

module_init(down_read_init);
module_exit(down_read_exit);

