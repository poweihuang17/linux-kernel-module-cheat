#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_inc_init(void);
static void __exit atomic_inc_exit(void);

atomic_t my_atomic;

int __init atomic_inc_init(void){
	atomic_set( &my_atomic, 5);
	printk("After atomic_set, my atomic counter is %d\n.", atomic_read(&my_atomic));
	atomic_inc( &my_atomic);
	printk("After atomic_inc, my atomic counter is %d\n.", atomic_read(&my_atomic));
	return 0;
}

void __exit atomic_inc_exit(void){
	printk("exit!\n");
}

module_init(atomic_inc_init);
module_exit(atomic_inc_exit);
