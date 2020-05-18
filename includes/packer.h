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
	int fd;


	// intern
	void *strtab;
	void *end_last_segment;

	Elf64_Shdr *section_tab;
	Elf64_Phdr *program_header;

	void *file;
	void *end;
	void *origin_entry_point;
	int big_endian;
} t_packer;

# define OK 0

# define ELF_START 1179403647

extern bool g_debug;
extern t_packer packer;






void print_section_name(Elf64_Shdr sections_tab[], char *strtab);
int check_header(void);
void *map_file(char *pathFile, uint64_t *p_size, int *p_fd);











#endif //WOODY_WOODPACKER_PACKER_H
