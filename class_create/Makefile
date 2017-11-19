# makefile which uses buildsystem to compile

obj-m := driver.o	#m indicates module y indicates built in bzImage


KERNSRC := /lib/modules/$(shell uname -r)/build

#path to the kernel build 

PWD := $(shell pwd)


modules:

	make -C $(KERNSRC) M=$(PWD) modules

	# C indicates changing the current directory to KERNSRC

	# M indicates move to the present working directory


modules_install:

	make -C $(KERNSRC) M=$(PWD) modules_install depmod -a

clean:

	make -C $(KERNSRC) M=$(PWD) clean
