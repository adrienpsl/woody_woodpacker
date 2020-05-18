/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "packer.h"

// todo check if correct value
void *find_strtab(void *start, Elf64_Ehdr *header, Elf64_Shdr *section_tab)
{
	return start + section_tab[header->e_shstrndx].sh_offset;
}

int check_header(void)
{

	packer.header = packer.file;

	// bad magic
	if (ELF_START != *(int *)packer.header)
	{
		ft_dprintf(STDERR_FILENO, "Magic is not ELF\n");
		return (-1);
	}

	if (packer.header->e_ident[EI_CLASS] != ELFCLASS64)
	{
		dprintf(STDERR_FILENO, "ELF is not 64bits\n");
		return (-1);
	}

	if (packer.header->e_ident[EI_DATA] == 0)
	{
		dprintf(STDERR_FILENO, "Invalid data encoding\n");
		return (-1);
	}

	else if (packer.header->e_ident[EI_DATA] == ELFDATA2MSB)
		packer.big_endian = 1;

	// todo check if in the file
	packer.origin_entry_point = packer.file + packer.header->e_entry;
	packer.section_tab = packer.file + packer.header->e_shoff;
	packer.program_header = packer.file + packer.header->e_phoff;

	packer.strtab = find_strtab(
		packer.file,
		packer.header,
		packer.section_tab
	);

	if (packer.strtab == NULL)
	{
		perror("strtab null");
		return (-1);
	}

	return (0);
}
