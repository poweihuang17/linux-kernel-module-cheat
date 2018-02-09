#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
static unsigned long data =0;
static struct tasklet_struct tasklet, tasklet1;

static void irq_tasklet_action(unsigned long data)
{
	printk("The state of the tasklet in the irq_tasklet_action is :%ld\n", (&tasklet)->state);
	printk("Tasklet runnning by Po-wei\n");
	return; 
}

static void irq_tasklet_action1(unsigned long data)
{
	printk("The state of the tasklet in the irq_tasklet_action1 is :%ld\n", (&tasklet1)->state);
	printk("Tasklet runnning by Po-wei\n");
	return; 
}
static int __init tasklet_hi_schedule_init(void)
{
	printk("Into tasklet_hi_schedule_init\n");
	
	tasklet_init(&tasklet, irq_tasklet_action,data);
	tasklet_init(&tasklet1, irq_tasklet_action1,data);
		
	printk("The state of the tasklet  is :%ld\n", (&tasklet)->state);
	printk("The state of the tasklet1 is :%ld\n", (&tasklet1)->state);
	
	tasklet_schedule(&tasklet);
	tasklet_hi_schedule(&tasklet1);
	
	printk("The state of the tasklet  is :%ld\n", (&tasklet)->state);
	printk("The state of the tasklet1 is :%ld\n", (&tasklet1)->state);
	tasklet_kill(&tasklet);
	tasklet_kill(&tasklet1);

	printk("Out tasklet_hi_schedule_init\n");
	return 0;
}

static void __exit tasklet_hi_schedule_exit(void)
{
	printk("Goodbye tasklet_hi_schedule.\n");
	return;
}

module_init(tasklet_hi_schedule_init);
module_exit(tasklet_hi_schedule_exit);
