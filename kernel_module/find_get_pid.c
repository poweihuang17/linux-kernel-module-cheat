//Question: Why does some function have two underscore? 

#include <linux/sched.h>
#include <linux/module.h>
#include <linux/pid.h>
MODULE_LICENSE("GPL");

static int __init find_get_pid_init(void)
{
	printk("into find_get_pid_init.\n");
	
	//Get the pid of cureent process. current is a predefined variable for this process.
	struct pid * current_pid= find_get_pid(current->pid);
	printk("The count of this process is :%d\n" pid->count);
	printk("The level of this proces is :%d\n", pid->level);

	return 0;
}

void __exit __find_get_pid_exit(void)
{
	printk("module exit ok!\n");
} 

module_init(__print_symbol_init);
module_exit(__print_symbol_exit);	
