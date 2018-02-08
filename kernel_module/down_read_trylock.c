#include <linux/rwsem.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_read_trylock_init(void);
static void __exit down_read_trylock_exit(void);
#define EXEC_DOWN_WRITE 1
struct rw_semaphore rwsem;


int __init down_read_trylock_init(void)
{
	int ret;
	init_rwsem(&rwsem);
	printk("After init_rwsem, rwsem.count:%ld\n", rwsem.count.counter);
	if( EXEC_DOWN_WRITE)
		{
		down_write(&rwsem);
		printk("Write lock acquired now!");
		}
	
	ret=down_read_trylock(&rwsem);
	if(ret)
	{
		printk("First down_read_trylock, rwsem.count:%ld\n", rwsem.count.counter);
        
		down_read_trylock(&rwsem);
		printk("Second down_read_trylock, rwsem.count:%ld\n", rwsem.count.counter);
		while(rwsem.count.counter!=0)
			{
				up_read(&rwsem);
			}	
	}
	else 
		printk("down_read_trylock failed!\n");
	return 0;
}

void __exit down_read_trylock_exit(void)
{
	printk("exit!\n");
}

module_init(down_read_trylock_init);
module_exit(down_read_trylock_exit);

