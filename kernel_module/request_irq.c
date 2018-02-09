#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int irq=3;

static irqreturn_t irq_handler(int data, void * dev_id)
{
	printk("The data is :%d\n", data);
	printk("In the interrupt handler function\n");
	return  IRQ_NONE;
}

static int __init request_irq_init(void)
{
	int result=0;
	printk("Into request_irq_init\n");
	result=request_irq(irq, irq_handler, IRQF_ONESHOT , "A_NEW_DEVICE", NULL);
	printk("The result of the request_irq is: %d\n", result);
	printk("Out request_irq_init\n");
	return 0;
}

static void __exit request_irq_exit(void)
{
	free_irq(irq, NULL);
	printk("Goodbye request_irq\n");
	return ;
}

module_init(request_irq_init);
module_exit(request_irq_exit);
