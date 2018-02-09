#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int irq=10;

static irqreturn_t irq_handler(int data, void * dev_id)
{
	printk("The data is :%d\n", data);
	printk("In the interrupt handler function\n");
	return  IRQ_NONE;
}
static struct irqaction act=
{
	.irq=10,
	.handler=irq_handler,
	.flags=IRQF_SHARED,
	.name="A new device",
	.dev_id=NULL
};

static int __init setup_irq_init(void)
{
	int result=0;
	printk("Into setup_irq_init\n");
	result=setup_irq(irq, &act);
	printk("The result of the setup_irq is: %d\n", result);
	printk("Out setup_irq_init\n");
	return 0;
}

static void __exit setup_irq_exit(void)
{
	remove_irq(irq, &act);
	printk("Goodbye setup_irq\n");
	return ;
}

module_init(setup_irq_init);
module_exit(setup_irq_exit);
