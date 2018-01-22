#include <linux/module.h>
#include <linux/init.h>
MODULE_LICENSE("GPL");
static int __init __module_text_address_init(void);
static void __exit __module_text_address_exit(void);


int fun_a(void)
{
	return 0;
}
static int var_b=4;

int __init __module_text_address_init(void)
{
	struct module *ret;
	unsigned long addr =(unsigned long) fun_a;

	//Disable interupt, so that module is not released during execution?
	preempt_disable();
	ret = __module_text_address(addr);
	preempt_enable();
	printk("It's about func_a.\n");
	//If return is not null, print the message of the module.
	if (ret!=NULL)
	{
		printk("ret->name: %s\n", ret->name);
		printk("ret->state: %d\n", ret->state);
		//There is no core_size in 4.x.
		//printk("ret->core_size: %d\n", ret->core_size);
		printk("refs of %s is %d \n", ret->name, module_refcount(ret));
	}
	else
	{
		printk("fun_a is not in text area!\n");
	}
	
	
	addr = (unsigned long) & var_b;
	preempt_disable();
	ret = __module_text_address(addr);
	preempt_enable();
	printk("It's about var_b.\n");

	if(ret !=NULL)
	{
	
		printk("ret->name: %s\n", ret->name);
		printk("ret->state: %d\n", ret->state);
		//There is no core_size in 4.x.
		//printk("ret->core_size: %d\n", ret->core_size);
		printk("refs of %s is %d \n", ret->name, module_refcount(ret));
	}
	else
	{
		printk("var_b is not in data area!\n");
	}

	return 0;
}

void __exit __module_text_address_exit(void)
{
	printk("module exit ok!\n");
} 

module_init(__module_text_address_init);
module_exit(__module_text_address_exit);	
