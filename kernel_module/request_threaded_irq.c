#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int irq=3;

static irqreturn_t irq_handler(int data, void * dev_id)
{
	printk("The data is :%d\n", data);
	printk("In the interrupt handler function\n");
	return  IRQ_WAKE_THREAD;
}

static irqreturn_t irq_thread_fn(int data, void * dev_id)
{
	printk("The data is :%d\n", data);
	printk("In the interrupt handler function\n");
	return IRQ_HANDLED;
}

static int __init request_threaded_irq_init(void)
{
	int result=0;
	printk("Into request_threaded_irq_init\n");
	result=request_threaded_irq(irq, irq_handler,irq_thread_fn,  IRQF_ONESHOT , "A_NEW_DEVICE", NULL);
	printk("The result of the request_threaded_irq is: %d\n", result);
	disable_irq(irq);
	enable_irq(irq);
	printk("Out request_threaded_irq_init\n");
	return 0;
}

static void __exit request_threaded_irq_exit(void)
{
	free_irq(irq, NULL);
	printk("Goodbye request_threaded_irq\n");
	return ;
}

module_init(request_threaded_irq_init);
module_exit(request_threaded_irq_exit);
