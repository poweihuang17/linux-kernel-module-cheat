#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_interruptible_init(void);
static void __exit down_interruptible_exit(void);
struct semaphore sema;

int __init down_interruptible_init(void)
{
	int ret;
	sema_init(&sema, 5);
	printk("After sema_init, sema.count:%d\n", sema.count);
	ret=down_interruptible(&sema);

	printk("First down_interruptible, sema.count:%d\n", sema.count);
	printk("First down_interruptible, ret= %d\n", ret);
	
	sema_init(&sema,0);
	ret=down_interruptible(&sema);
	printk("Second down_interruptible, sema.count:%d\n", sema.count);
	printk("Second down_interruptible, ret:%d\n", ret);
	
	return 0;
}

void __exit down_interruptible_exit(void)
{
	printk("exit!\n");
}

module_init(down_interruptible_init);
module_exit(down_interruptible_exit);

