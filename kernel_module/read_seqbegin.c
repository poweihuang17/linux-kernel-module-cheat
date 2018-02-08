#include <linux/seqlock.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int __init read_seqbegin_init(void);
static void __exit read_seqbegin_exit(void);
seqlock_t seqlock;

int __init read_seqbegin_init(void)
{
	int ret;
	seqlock_init(&seqlock);
	printk("After seqlock_init, sequence: %d\n\n", seqlock.seqcount.sequence);
	
	write_seqlock(&seqlock);
	printk("After write_seqlock, sequence: %d\n\n", seqlock.seqcount.sequence);
	write_sequnlock(&seqlock);
	printk("After write_sequnlcok, sequence:%d\n\n", seqlock.seqcount.sequence);
	ret=read_seqbegin(&seqlock);
	printk("ret=%d\n", ret);
	printk("After read_seqbegin, seqlock.sequence:%d\n\n", seqlock.seqcount.sequence);
	return 0;
}

void __exit read_seqbegin_exit(void)
{
	printk("exit!\n");
}

module_init(read_seqbegin_init);
module_exit(read_seqbegin_exit);

