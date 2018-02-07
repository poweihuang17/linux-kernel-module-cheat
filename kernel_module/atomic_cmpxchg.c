#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_cmpxchg_init(void);
static void __exit atomic_cmpxchg_exit(void);

atomic_t my_atomic;

int __init atomic_cmpxchg_init(void){

	int ret, old, new;
	atomic_set( &my_atomic, 4);
	old=3;
	new=2;
	ret=atomic_cmpxchg(&my_atomic, old, new);

	printk("After first atomic_cmpxchg, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("return ret = %d\n", ret);

	old=4;
	new=2;
	ret=atomic_cmpxchg( &my_atomic,old,new);
	printk("After second atomic_cmpxchg, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("return ret = %d\n", ret);
	return 0;
}

void __exit atomic_cmpxchg_exit(void){
	printk("exit!\n");
}

module_init(atomic_cmpxchg_init);
module_exit(atomic_cmpxchg_exit);
