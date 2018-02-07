#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_add_unless_init(void);
static void __exit atomic_add_unless_exit(void);

atomic_t my_atomic;

int __init atomic_add_unless_init(void){
	int ret, a;
	atomic_set( &my_atomic, 10);
	a=2;

	ret = atomic_add_unless(&my_atomic, a, 10);
	
	printk("After first atomic_add_unless, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("ret=%d\n.", ret);
	printk("\n");

	atomic_set(&my_atomic, 4);
	a=2;
	ret=atomic_add_unless( &my_atomic,a,10);
	printk("After second atomic_add_unless, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("ret= %d\n.", ret);
	return 0;
}

void __exit atomic_add_unless_exit(void){
	printk("exit!\n");
}

module_init(atomic_add_unless_init);
module_exit(atomic_add_unless_exit);
