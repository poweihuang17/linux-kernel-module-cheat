#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_timeout_init(void);
static void __exit down_timeout_exit(void);
struct semaphore sema;

int __init down_timeout_init(void)
{
	int ret;
	long iffies=1000;
	sema_init(&sema, 5);
	printk("After sema_init, sema.count:%d\n", sema.count);
	ret=down_timeout(&sema,iffies);

	printk("First down_timeout, sema.count:%d\n", sema.count);
	printk("First down_timeout, ret= %d\n", ret);
	
	sema_init(&sema,0);
	ret=down_timeout(&sema,iffies);
	printk("Second down_timeout, sema.count:%d\n", sema.count);
	printk("Second down_timeout, ret:%d\n", ret);
	
	return 0;
}

void __exit down_timeout_exit(void)
{
	printk("exit!\n");
}

module_init(down_timeout_init);
module_exit(down_timeout_exit);

