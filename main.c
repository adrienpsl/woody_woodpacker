// go to the text part, and add some data at start.
// need to understand how, the element is load in memory, and how
// it's used in the program.

// maybe I can do that project only with vim, and noting other, just for the fun
// and have a best mind :).


// so, ok. I will do that, during the next month I will only use vim.

# include "packer.h"

t_packer packer = {};
bool g_debug = false;

void print_section_name(Elf64_Shdr sections_tab[], char *strtab)
{

	Elf64_Shdr *current;
	char *section_name;
	(void)strtab;

	for (uint64_t i = 0; i < packer.header->e_shnum; ++i)
	{
		current = sections_tab + i;
		section_name = packer.strtab + current->sh_name;
		printf("%s %d %p\n", section_name,
			packer.header->e_shstrndx + current->sh_name, packer.strtab);
	}
}

int main(void)
{
	packer.start = map_file(
		"/home/adpusel/Desktop/osxShare/woody_woodpacker/resouce_2/sample",
		&packer.size, &packer.fd);

	if (NULL == packer.start)
		perror("packer");

	if (OK != check_header())
		return -1;

	printf("%d \n", packer.header->e_shstrndx);
	print_section_name(packer.section_tab, packer.strtab);


	// I can add whatever I want, and just regoing at the new entry point.
	// I didn't even need to see what's do the section.
	// yeah
	// add some stuff at the end,

	// how add my code at the end of the start?


	// after my reading, It seem obvious that a bad binary can have
	// these bad stuff, and break all!
	// I don't want touch the binary a lot
	// if a section is at the end of my binary all will be broken
	// if that happen, all my data can be kein!
	// so, the best is to write at the end of the binary to be sure
	// that nothing will be broken! yeah! wonderful, amazing!


	return (0);
}
