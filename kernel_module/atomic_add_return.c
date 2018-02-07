#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_add_return_init(void);
static void __exit atomic_add_return_exit(void);

atomic_t my_atomic;

int __init atomic_add_return_init(void){
	int ret, i;
	atomic_set( &my_atomic, 5);
	
	i=2;
	ret = atomic_add_return(i, &my_atomic);
	
	printk("After atomic_add_return, my atomic counter is %d\n.", atomic_read(&my_atomic));
	printk("return ret =%d\n.", ret);
	printk("\n");

	return 0;
}

void __exit atomic_add_return_exit(void){
	printk("exit!\n");
}

module_init(atomic_add_return_init);
module_exit(atomic_add_return_exit);
