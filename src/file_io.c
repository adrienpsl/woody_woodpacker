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

// map the start in memory, and check all error.
void *map_file(char *pathFile, uint64_t *p_size, int *p_fd)
{
	int fd;
	int size;
	void *file;

	if (g_debug)
		printf("Try open %s", pathFile);

	fd = open(pathFile, O_RDWR);
	if (fd < 0)
		return (NULL);

	size = lseek(fd, 0, SEEK_END);
	if (-1 == size)
		return (NULL);

	file = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (MAP_FAILED == file)
		return (NULL);

	*p_size = size;
	*p_fd = fd;

	return file;
}
