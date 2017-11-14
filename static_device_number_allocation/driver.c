#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
dev_t device;
static int hello_init(void)
{
	int ret;
	device = MKDEV(200, 2);
	printk(KERN_ALERT"Major Number:%d\t Minor Number:%d\n", MAJOR(device), MINOR(device));

	ret = register_chrdev_region(device, 1, "jamal");

	return ret;
}

static void hello_exit(void)
{
	printk(KERN_ALERT"Hello exit\n");
	unregister_chrdev_region(device, 1);
}
	
module_init(hello_init);
module_exit(hello_exit);
