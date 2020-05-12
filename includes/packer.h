//
// Created by adpusel on 5/12/20.
//

#ifndef WOODY_WOODPACKER_PACKER_H
#define WOODY_WOODPACKER_PACKER_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/mman.h>
# include <unistd.h>
# include <elf.h>

# include "libft.h"
# include "ft_printf.h"

typedef struct s_packer
{
	Elf64_Ehdr *header;
	uint64_t size;
	void *current;
	void *file;
	void *start;
	void *end;
	void *origin_entry_point;
	void *sh_off;
	uint64_t sh_num;
	int big_endian;
} t_packer;

# define OK 0

# define ELF_START 1179403647

#endif //WOODY_WOODPACKER_PACKER_H
