#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_add_negative_init(void);
static void __exit atomic_add_negative_exit(void);

atomic_t my_atomic;

int __init atomic_add_negative_init(void){
	int ret, i;
	atomic_set( &my_atomic, -3);
	
	i=2;
	ret = atomic_add_negative(i, &my_atomic);
	
	printk("After atomic_add_negative, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("ret=%d\n.", ret);
	printk("\n");

	i=3;
	ret=atomic_add_negative(i, &my_atomic);
	printk("After atomic_add_negative, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("ret= %d\n.", ret);
	return 0;
}

void __exit atomic_add_negative_exit(void){
	printk("exit!\n");
}

module_init(atomic_add_negative_init);
module_exit(atomic_add_negative_exit);
