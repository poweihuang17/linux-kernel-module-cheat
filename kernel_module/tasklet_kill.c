#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
static unsigned long data =0;
static struct tasklet_struct tasklet;

static void irq_tasklet_action(unsigned long data)
{
	printk("The state of the tasklet in the irq_tasklet_action is :%ld\n", (&tasklet)->state);
	printk("Tasklet runnning by Po-wei\n");
	return; 
}

static int __init tasklet_kill_init(void)
{
	printk("Into tasklet_kill_init\n");
	tasklet_init(&tasklet, irq_tasklet_action,data);
	
	printk("The data value of the tasklet after init is :%ld\n", tasklet.state);
	tasklet_schedule(&tasklet);
	
	printk("The data value of the tasklet after schedule is :%ld\n", tasklet.state);
	
	tasklet_kill(&tasklet);
	printk("The data value of the tasklet after tasklet_kill is :%ld\n", tasklet.state);
	
	printk("Out tasklet_kill_init\n");
	return 0;
}

static void __exit tasklet_kill_exit(void)
{
	printk("Goodbye tasklet_kill.\n");
	return;
}

module_init(tasklet_kill_init);
module_exit(tasklet_kill_exit);
