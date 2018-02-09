#include <linux/interrupt.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static unsigned long data =0;
static struct tasklet_struct tasklet;

static void irq_tasklet_action(unsigned long data)
{
	int result=-1;
	printk("The state of the tasklet in the irq_tasklet_action is :%ld\n", (&tasklet)->state);
	printk("Tasklet runnning by Po-wei\n");
	result=tasklet_trylock(&tasklet);
	if(result==0)
		printk("tasklet_trylock failed\n");
	else
		printk("tasklet_trylock success\n");
	printk("out irq_tasklet_action\n");
	return; 
}

static int __init tasklet_trylock_init(void)
{
	int result=-1;
	printk("Into tasklet_trylock_init\n");
	tasklet_init(&tasklet, irq_tasklet_action,data);
	tasklet_schedule(&tasklet);

	printk("The state of the tasklet before tasklet_trylock  is :%ld\n", tasklet.state);
	result=tasklet_trylock(&tasklet);
	
	if(result==0)
		printk("Success!\n");
	else 
		printk("Failed!\n");
	
	printk("The state of the tasklet after tasklet_trylock is :%ld\n", tasklet.state);
	tasklet_unlock(&tasklet);
	printk("The state of the tasklet after tasklet_unlock is :%ld\n", tasklet.state);

	tasklet_kill(&tasklet);	
	
	printk("Out tasklet_trylock_init\n");
	return 0;
}

static void __exit tasklet_trylock_exit(void)
{
	printk("Goodbye tasklet_trylock.\n");
	return;
}

module_init(tasklet_trylock_init);
module_exit(tasklet_trylock_exit);
