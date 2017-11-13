#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


static int a = 3;
static int b = 4;

extern int add(int a, int b);

module_param(a, int, S_IRUGO);
module_param(b, int, S_IRUGO);

static int average(int a, int b)
{
	return add(a,b)/2;
}

static int __init export_init(void)
{
	printk("Hello:%d\n", average(a, b));
	return 0;
}


static void __exit export_exit(void)
{
	printk("Exit\n");

}

MODULE_LICENSE("GPL");
//EXPORT_SYMBOL_GPL(add);
module_init(export_init)
module_exit(export_exit)
