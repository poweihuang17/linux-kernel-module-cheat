#include <linux/sched.h>
#include <linux/module.h>
#include <linux/pid.h>
MODULE_LICENSE("GPL");

static int __init __task_pid_nr_ns_init(void)
{
	printk("into __task_pid_nr_ns_init.\n");
	
	//Get the pid of cureent process. current is a predefined variable for this process.
	struct pid * cureent_pid= find_get_pid(
	return 0;
}

void __exit __print_symbol_exit(void)
{
	printk("module exit ok!\n");
} 

module_init(__print_symbol_init);
module_exit(__print_symbol_exit);	
