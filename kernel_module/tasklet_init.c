#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
static unsigned long data =10;
static struct tasklet_struct tasklet;

static void irq_tasklet_action(unsigned long data)
{
	printk("The state of the tasklet is :%ld\n", (&tasklet)->state);
	printk("Tasklet runnning by Po-wei\n");
	return; 
}

static int __init tasklet_init_init(void)
{
	printk("Into tasklet_init_init\n");
	printk("The data value of the tasklet is : %ld\n", tasklet.data);
	if(tasklet.func==NULL)
		{
		printk("The tasklet has not been initialized\n");
		}
	
	tasklet_init(&tasklet, irq_tasklet_action,data);
	
	printk("The data value of the tasklet is :%ld\n", tasklet.data);
	if(tasklet.func==NULL)
		{
		printk("The tasklet has not been initialized.\n");
		}
	else
		{
		printk("The tasklet has been initialized.\n");
		}
	printk("Out tasklet_init_init\n");
	return 0;
}

static void __exit tasklet_init_exit(void)
{
	printk("Goodbye tasklet_init.\n");
	return;
}

module_init(tasklet_init_init);
module_exit(tasklet_init_exit);
