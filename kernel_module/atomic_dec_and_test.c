#include <asm/atomic.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
MODULE_LICENSE("GPL");
static int __init atomic_dec_and_test_init(void);
static void __exit atomic_dec_and_test_exit(void);

atomic_t my_atomic;

int __init atomic_dec_and_test_init(void){
	int ret, num;
	ret=num=0;
	atomic_set( &my_atomic, 3);
	printk("After atomic_set, my atomic counter is %d\n.", atomic_read(&my_atomic));
	while((ret=atomic_dec_and_test( &my_atomic))==0)
	{
		num++;
	}
	printk("num=%d\n",num);
	return 0;
}

void __exit atomic_dec_and_test_exit(void){
	printk("exit!\n");
}

module_init(atomic_dec_and_test_init);
module_exit(atomic_dec_and_test_exit);
