#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_init(void);
static void __exit down_exit(void);
struct semaphore sema;

int __init down_init(void)
{
	sema_init(&sema, 5);
	printk("After sema_init, sema.count:%d\n", sema.count);
	down(&sema);

	printk("First down, sema.count:%d\n", sema.count);
	
//	sema_init(&sema,0);
//	down(&sema);
//	printk("Second down, sema.count:%d\n",sema.count);
	
	return 0;
}

void __exit down_exit(void)
{
	printk("exit!\n");
}

module_init(down_init);
module_exit(down_exit);

