#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
#include <linux/wait.h>
#include <linux/list.h>
#include <linux/kthread.h>
#include <linux/delay.h>
MODULE_LICENSE("GPL");

//Define global variable
static wait_queue_head_t head; //
struct task_struct *old_thread;

int my_function(void * argc)
{
	printk("In the kernel thread function!\n");
	//current is a special name.
	printk("The current pid is :%d\n", current->pid);

}


