#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("GPL");

static char *whom = "world";
static int howmany = 1;

module_param(howmany, int, 0);
module_param(whom, charp, S_IRUGO);

static int __init hello_init(void)
{
	printk(KERN_ALERT"Hello INIT\n");
	while(howmany > 0 )
	{
		printk("%s\n", whom);
		howmany--;
	}
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT"Hello EXIT\n");

}


module_init(hello_init)
module_exit(hello_exit)
