#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

int init_module(void)
{
	printk(KERN_ALERT"Hello World\n");
	return 5;
}

void cleanup_module(void)
{
	printk(KERN_ALERT"Hello exit\n");
}

//module_init(hello_init);
//module_exit(hello_exit);
