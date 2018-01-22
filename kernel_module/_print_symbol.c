//Question: Why do we export symbol?

#include <linux/module.h>
#include <linux/init.h>
#include <linux/kallsyms.h>

MODULE_LICENSE("GPL");
static int __init __print_symbol_init(void);
static void __exit __print_symbol_exit(void);

// Symbol a_symbol
int a_symbol(void)
{
	return 1;
}

// What's the meaning of this export_symbol?
EXPORT_SYMBOL(a_symbol);


int __init __print_symbol_init(void)
{
	char * fmt;
	unsigned long address;
	char *name;
	struct module * fmodule = NULL;

	address = (unsigned long) __builtin_return_address(0);
	fmt="it's the first part, \n %s";
	__print_symbol(fmt,address);

	printk("\n\n");
	
	name="hello";
	fmodule=find_module(name);	
	if (fmodule!=NULL)
	{
		printk("fmodule->name: %s\n", fmodule->name);
		//Assign the start address of module to "address"
		address=(unsigned long) fmodule->init;
		fmt="It's the second part, \n %s";
		__print_symbol(fmt, address);
	}
	
	printk("\n\n");
	
	//Assign address with &a_symbol +5.
	address=(unsigned long) a_symbol+5;
	fmt="It's the third part, \n %s";
	__print_symbol(fmt,address);	
	printk("\n\n");	
	return 0;
}

void __exit __print_symbol_exit(void)
{
	printk("module exit ok!\n");
} 

module_init(__print_symbol_init);
module_exit(__print_symbol_exit);	
