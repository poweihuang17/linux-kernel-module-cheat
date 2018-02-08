#include <linux/rwsem.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init downgrade_write_init(void);
static void __exit downgrade_write_exit(void);
#define EXEC_DOWNGRADE_WRITE 1
struct rw_semaphore rwsem;


int __init downgrade_write_init(void)
{
	init_rwsem(&rwsem);
	printk("After init_rwsem, rwsem.count:%ld\n", rwsem.count.counter);
	down_write(&rwsem);
	if( EXEC_DOWNGRADE_WRITE)
		{
		downgrade_write(&rwsem);
		printk("Write downgraded now!");
		printk("After downgraded, rwsem.count:%ld\n", rwsem.count.counter);
		}
	
	down_read(&rwsem);
	printk("After down_read, rwsem.count:%ld\n", rwsem.count.counter);
        
	while(rwsem.count.counter!=0)
		{
			up_read(&rwsem);
		}	

	return 0;
}

void __exit downgrade_write_exit(void)
{
	printk("exit!\n");
}

module_init(downgrade_write_init);
module_exit(downgrade_write_exit);

