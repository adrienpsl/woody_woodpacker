// go to the text part, and add some data at start.
// need to understand how, the element is load in memory, and how
// it's used in the program.

// maybe I can do that project only with vim, and noting other, just for the fun
// and have a best mind :).

// so, ok. I will do that, during the next month I will only use vim.
#include <stdio.h>
#include <string.h>
#include <zconf.h>
#include <fcntl.h>
# include <stdlib.h>
# include "sys/mman.h"

// count file size ?
// mmap file size  ?
// check if the end is same start.

//long int get_file_size(int file)
//{
//}
typedef struct s_packer
{
	void *file;
} t_packer;

t_packer packer = {};

void *map_file()
{
	int fd;
	int size;
	void *file;

	fd = \
        open("/Users/adpusel/42/Woody_woodpacker/resources/hello", O_RDWR);
	if (fd < 0)
	{
		perror("open :");
		exit(42);
	}

	if (-1 == (size = lseek(fd, 0, SEEK_END)))
	{
		perror("open :");
		exit(42);
	};

	if (MAP_FAILED == (file = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)))
	{
		perror("open :");
		exit(42);
	}
	return file;
}

int main()
{
	void *file;

	file = map_file();

	// check the name

	// parse the file.

	// open file

	// get end

	// ok let's go!

	return (0);
}
