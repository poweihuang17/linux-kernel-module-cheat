#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_inc_and_test_init(void);
static void __exit atomic_inc_and_test_exit(void);

atomic_t my_atomic;

int __init atomic_inc_and_test_init(void){
	int ret;
	atomic_set( &my_atomic, -3);
	ret=atomic_inc_and_test(&my_atomic);
	printk("ret=%d\n", ret); 
	atomic_set(&my_atomic,-1);
	ret=atomic_inc_and_test(&my_atomic);
	printk("ret=%d\n",ret);
	return 0;
}

void __exit atomic_inc_and_test_exit(void){
	printk("exit!\n");
}

module_init(atomic_inc_and_test_init);
module_exit(atomic_inc_and_test_exit);
