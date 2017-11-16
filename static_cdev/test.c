#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int fd = open("/dev/jamal", O_WRONLY);
	printf("fd:%d\n", fd);
	close(fd);

}
