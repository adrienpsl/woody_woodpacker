// go to the text part, and add some data at file.
// need to understand how, the element is load in memory, and how
// it's used in the program.

// maybe I can do that project only with vim, and noting other, just for the fun
// and have a best mind :).


// so, ok. I will do that, during the next month I will only use vim.

# include "packer.h"

t_packer packer = {};
bool g_debug = false;

Elf64_Phdr *find_last_segment(Elf64_Phdr phdr[], uint64_t phnum)
{
	Elf64_Phdr *current;
	Elf64_Phdr *last_segment;

	// todo check there is phnum and if it's little than
	last_segment = phdr;
	for (uint64_t i = 0; i < phnum; ++i)
	{
		printf("%lx \n", current->p_offset);
		if (current->p_offset >= last_segment->p_offset)
			last_segment = current;
		current = phdr + i;
	}
	return (last_segment);
}

void *get_end_last_segment(void *file, Elf64_Phdr *phdr)
{
	return (
		file
		+ phdr->p_offset
		+ phdr->p_filesz
	);
}

void updateLastSegmentHeader(Elf64_Phdr *last)
{
	last->p_flags = PF_R | PF_X;
}

int main(void)
{
	packer.file = map_file(
		"/home/adpusel/Desktop/osxShare/woody_woodpacker/resouce_2/a.out",
		&packer.size, &packer.fd);

	if (NULL == packer.file)
		perror("packer");

	if (OK != check_header())
		return -1;

	Elf64_Phdr *last;
	last = find_last_segment(packer.program_header, packer.header->e_phnum);
	updateLastSegmentHeader(last);
	packer.end_last_segment = get_end_last_segment(packer.file, last);

	char *str = "test at the end of that file mon gars c'est cool de faire ca!";
	sprintf(packer.end_last_segment, "%s", str);
	last->p_filesz = last->p_filesz + ft_strlen(str);

	int out = open(
		"/home/adpusel/Desktop/osxShare/woody_woodpacker/resouce_2/new",
		O_RDWR | O_CREAT, 777);
	if (out < 1)
		perror("out ");

	write(out, packer.file, packer.size + ft_strlen(str));

	close(out);
	close(packer.fd);
	munmap(packer.file, packer.size);




	// add some shit at the end, and test it :).
	// change the ri



	// make the last section bigger,
	//
	//	print_section_name(packer.section_tab, packer.strtab);


	// I can add whatever I want, and just regoing at the new entry point.
	// I didn't even need to see what's do the section.
	// yeah
	// add some stuff at the end,

	// how add my code at the end of the file?


	// after my reading, It seem obvious that a bad binary can have
	// these bad stuff, and break all!
	// I don't want touch the binary a lot
	// if a section is at the end of my binary all will be broken
	// if that happen, all my data can be kein!
	// so, the best is to write at the end of the binary to be sure
	// that nothing will be broken! yeah! wonderful, amazing!


	return (0);
}
