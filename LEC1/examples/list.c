#include <fcntl.h>   /* open() */
#include <unistd.h>  /* read() */
#include <stdio.h>   /* printf() */
#include <stdlib.h>  /* exit() */

// list.c: list file names in the current directory

struct dirent {
	unsigned short inum;
	char name[14];
};

int main()
{
	int fd;
	struct dirent e;

	fd = open(".", 0);
	while (read(fd, &e, sizeof(e)) == sizeof(e)) {
		printf("hello\n");
		if (e.name[0] != '\0')
			printf("%s\n", e.name);
	}

	exit(0);
}
