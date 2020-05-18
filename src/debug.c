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
