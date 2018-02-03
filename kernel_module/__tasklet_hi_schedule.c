#include <linux/interrupt.h>
#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
static unsigned long data=0;
static struct tasklet_struct tasket, tasklet1;

//Self-defined interrupt processing function

static void irq_tasklet_action(unsigned long data)
{
	printk("In irq_tasklet_action, the state of the tasklet is :%d\n",(&tasklet)->state);
	printk("tasklet running. by po-wei\n");
	return;
}

static void riq_tasklet_action1(unsigned long data)
{
	printk("In irq_tasklet_action1, the state of the tasklet is :%\n", (&tasklet1)->state);
	printk("tasklet1 running, by po-wei\n");
	return;
}

static int __init __tasklet_hi_schedule_init(void)
{
	printk("Into __tasklet_hi_schedule\n");

}
