#include <linux/rwsem.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_write_init(void);
static void __exit down_write_exit(void);
#define EXEC_DOWN_READ 0
struct rw_semaphore rwsem;


int __init down_write_init(void)
{
	init_rwsem(&rwsem);
	printk("After init_rwsem, rwsem.count:%ld\n", rwsem.count.counter);
	if( EXEC_DOWN_READ)
		{
		down_read(&rwsem);
		printk("read lock acquired now!");
		}
	
	down_write(&rwsem);
	printk("First down_write, rwsem.count:%ld\n", rwsem.count.counter);
        up_write(&rwsem);
	printk("After up_write, count:%ld\n", rwsem.count.counter);

	//down_write(&rwsem);
	//printk("Second down_write, rwsem.count:%ld\n", rwsem.count.counter);
	while(rwsem.count.counter!=0)
		{
			up_read(&rwsem);
		}	

	return 0;
}

void __exit down_write_exit(void)
{
	printk("exit!\n");
}

module_init(down_write_init);
module_exit(down_write_exit);

