#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init down_killable_init(void);
static void __exit down_killable_exit(void);
struct semaphore sema;

int __init down_killable_init(void)
{
	int ret;
	sema_init(&sema, 5);
	printk("After sema_init, sema.count:%d\n", sema.count);
	ret=down_killable(&sema);

	printk("First down_killable, sema.count:%d\n", sema.count);
	printk("First down_killable, ret= %d\n", ret);
	
	sema_init(&sema,0);
	ret=down_killable(&sema);
	printk("Second down_killable, sema.count:%d\n", sema.count);
	printk("Second down_killable, ret:%d\n", ret);
	
	return 0;
}

void __exit down_killable_exit(void)
{
	printk("exit!\n");
}

module_init(down_killable_init);
module_exit(down_killable_exit);

