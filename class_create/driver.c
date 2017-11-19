#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");
dev_t device;
struct cdev mydev;
struct class *jamal_class;
struct device *jamal_device;

int jamal_open(struct inode *inode, struct file *filp)
{
	printk("%s\n", __func__);
	printk("Mode:%d\n", filp->f_mode);
	printk("Major Number:%d\t Minor Number:%d\n", imajor(inode), iminor(inode));
	return 0;
}

int jamal_release(struct inode *inode, struct file *filp)
{
	printk("%s\n", __func__);
	return 0;
}


struct file_operations jamal_fops = {
	.owner = THIS_MODULE,
	.open = jamal_open,
	.release = jamal_release,
};

static int hello_init(void)
{
	int ret;
	device = MKDEV(200, 2);
	printk(KERN_ALERT"Major Number:%d\t Minor Number:%d\n", MAJOR(device), MINOR(device));

	ret = register_chrdev_region(device, 1, "jamal");

	jamal_class = class_create(THIS_MODULE, "jamal");

	if ( IS_ERR(jamal_class) )
	{
		unregister_chrdev_region(device, 1);
		return PTR_ERR(jamal_class);
	}

	jamal_device = device_create(jamal_class, NULL, device, NULL, "jamal");
	if ( IS_ERR(jamal_device))
	{
		class_destroy(jamal_class);
		unregister_chrdev_region(device, 1);
		return PTR_ERR(jamal_class);
	}

	if ( ret == 0 )
	{
		cdev_init(&mydev, &jamal_fops);

		ret = cdev_add(&mydev, device, 1);
	}
	
	

	return ret;
}

static void hello_exit(void)
{
	printk(KERN_ALERT"Hello exit\n");
	device_destroy(jamal_class, device);
	class_destroy(jamal_class);
	cdev_del(&mydev);
	unregister_chrdev_region(device, 1);
}
	
module_init(hello_init);
module_exit(hello_exit);
