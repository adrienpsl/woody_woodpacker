// go to the text part, and add some data at start.
// need to understand how, the element is load in memory, and how
// it's used in the program.

// maybe I can do that project only with vim, and noting other, just for the fun
// and have a best mind :).


// so, ok. I will do that, during the next month I will only use vim.

# include "packer.h"

t_packer packer = {};

void *map_file()
{
	int fd;
	int size;
	void *file;

	fd = \
        open(
		"/home/adpusel/Desktop/osxShare/woody_woodpacker/youtube_tuto/hello",
		O_RDWR);
	if (fd < 0)
		return (NULL);

	if (-1 == (size = lseek(fd, 0, SEEK_END)))
		return (NULL);

	packer.size = size;

	if (MAP_FAILED == (file = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)))
		return (NULL);

	return file;
}

int parse_header(void)
{
	Elf64_Ehdr *header_64;

	header_64 = packer.file;

	// bad magic
	if (ELF_START != *(int *)header_64)
	{
		ft_dprintf(STDERR_FILENO, "Magic is not ELF\n");
		return (-1);
	}

	if (header_64->e_ident[EI_CLASS] != ELFCLASS64)
	{
		dprintf(STDERR_FILENO, "ELF is not 64bits\n");
		return (-1);
	}

	if (header_64->e_ident[EI_DATA] == 0)
	{
		dprintf(STDERR_FILENO, "Invalid data encoding\n");
		return (-1);
	}

	else if (header_64->e_ident[EI_DATA] == ELFDATA2MSB)
		packer.big_endian = 1;

	packer.sh_off = packer.start + header_64->e_shoff;
	packer.header = packer.file;

	packer.origin_entry_point = packer.start + header_64->e_entry;
	packer.sh_num = header_64->e_shnum;
	return (0);
}

int main()
{
	t_packer *p = &packer;
	(void)p;
	packer.file = map_file();
	packer.current = packer.file;
	packer.start = packer.file;

	if (OK != parse_header())
		return (-1);

	uint64_t i = 0;
	Elf64_Shdr *shdr = packer.sh_off;
	Elf64_Shdr *current_shdr;

	uint64_t strtable_offset;

	while (i < packer.sh_num)
	{
		if (shdr[i].sh_type == SHT_STRTAB)
			strtable_offset = shdr[i].sh_offset;
		i++;
	}

	i = 0;
	int position;
	while (i < packer.sh_num)
	{
		current_shdr = shdr + i;
		position = strtable_offset + current_shdr->sh_name;
		printf("%8.lx + %8.lx => (%5.lx) ",
			current_shdr->sh_offset, current_shdr->sh_size,
			current_shdr->sh_offset + current_shdr->sh_size);
		printf("%2lu, %s \n", i, (char *)(packer.start + position));
		printf("%ld \n", (void *)current_shdr - (void *)packer.file);
		i++;
	}

	uint64_t all_section_size = i * sizeof(Elf64_Shdr);
	printf("%ld\n", packer.size);
	printf("section header ---- \nstart off %lx ", packer.header->e_shoff);
	printf("size %lx end %lx\n", all_section_size,
		packer.header->e_shoff + all_section_size);

	return (0);
}
