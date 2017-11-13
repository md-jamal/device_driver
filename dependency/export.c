#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


static int a = 3;
static int b = 4;

module_param(a, int, S_IRUGO);
module_param(b, int, S_IRUGO);

static int add(int a, int b)
{
	return a+b;
}

static int __init export_init(void)
{
	printk("Hello:%d\n", add(a, b));
	return 0;
}


static void __exit export_exit(void)
{
	printk("Exit\n");

}

MODULE_LICENSE("GPL");
EXPORT_SYMBOL_GPL(add);
module_init(export_init)
module_exit(export_exit)
