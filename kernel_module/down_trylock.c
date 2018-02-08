#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_trylock_init(void);
static void __exit down_trylock_exit(void);
struct semaphore sema;

int __init down_trylock_init(void)
{
	int ret;
	sema_init(&sema, 5);
	printk("After sema_init, sema.count:%d\n", sema.count);
	ret=down_trylock(&sema);

	printk("First down_trylock, sema.count:%d\n", sema.count);
	printk("First down_trylock, ret= %d\n", ret);
	
	sema_init(&sema,0);
	ret=down_trylock(&sema);
	printk("Second down_trylock, sema.count:%d\n", sema.count);
	printk("Second down_trylock, ret:%d\n", ret);
	
	return 0;
}

void __exit down_trylock_exit(void)
{
	printk("exit!\n");
}

module_init(down_trylock_init);
module_exit(down_trylock_exit);

