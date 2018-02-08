#include <linux/semaphore.h>
#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int __init up_init(void);
static void __exit up_exit(void);
struct semaphore sema;

int __init up_init(void)
{
	sema_init(&sema, 2);
	printk("After sema_init, sema.count:%d\n", sema.count);
	down(&sema);

	printk("First down, sema.count:%d\n", sema.count);
	
	up(&sema);
	
	printk("After up, sema.count:%d\n", sema.count);

//	sema_init(&sema,0);
//	up(&sema);
//	printk("Second up, sema.count:%d\n",sema.count);
	
	return 0;
}

void __exit up_exit(void)
{
	printk("exit!\n");
}

module_init(up_init);
module_exit(up_exit);

