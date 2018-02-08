#include <linux/seqlock.h>
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int __init read_seqretry_init(void);
static void __exit read_seqretry_exit(void);
seqlock_t seqlock;

int __init read_seqretry_init(void)
{
	int ret;
	seqlock_init(&seqlock);
	printk("After seqlock_init, sequence: %d\n\n", seqlock.seqcount.sequence);
	
	write_seqlock(&seqlock);
	printk("After write_seqlock, sequence: %d\n\n", seqlock.seqcount.sequence);
	write_sequnlock(&seqlock);
	printk("After write_sequnlcok, sequence:%d\n\n", seqlock.seqcount.sequence);
	do{
		ret= read_seqbegin(&seqlock);
		printk("ret=%d\n", ret);
	}while(read_seqretry(&seqlock, ret));
	
	return 0;
}

void __exit read_seqretry_exit(void)
{
	printk("exit!\n");
}

module_init(read_seqretry_init);
module_exit(read_seqretry_exit);

