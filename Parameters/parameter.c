#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

static int a = 2;
static int b = 2;
/*Write simple Add module which takes parameters at load time */
module_param(a, int, S_IRUGO);
module_param(b, int, S_IRUGO);

static int __init hello_init(void)
{
	printk(KERN_ALERT"Hello INIT\n");
	printk(KERN_ALERT"a+b:%d\n", a+b);
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT"Hello EXIT\n");

}


module_init(hello_init)
module_exit(hello_exit)
