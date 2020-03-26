/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:04:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/27 03:11:55 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

ssize_t	read_to_buffer(int fd, t_gnl_material *material)
{
	ssize_t readn;

	readn = read(fd, material->buffer, BUFFER_SIZE);
	if (readn == -1 || readn == 0)
		return (readn);
	material->last_idx = readn - 1;
	material->start_idx = 0;
	material->value_to_print_exist = 1;
	return (readn);
}

int	expaned_memory_size(char **line, int *total_size)
{
	//return (-1); // 에러나면 
	return (1);
}

int	copy_all_buffer_to_line(char **line, t_gnl_material *material)
{
	// return (0); // 다 복사 못했음 중간에 개행 만나서
	return (1); // 다복사했음 
}

void	setting_material(t_gnl_material *material)
{
	
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_material material;
	size_t total_size;
	ssize_t readn;

	if (material.value_to_print_exist == 0)
	{
		readn = read_to_buffer(fd, &material);
		if (readn == -1 || readn == 0)
			return (readn);
	}
	total_size = 0;
	if (expand_memory_size(line, &total_size) == -1)  // 함수 구현해야함 
		return (-1);
	while (copy_all_buffer(line, &material) == 1)
	{
		material.value_to_print_exist = 0;
		readn = read_to_buffer(fd, &material);
		if (readn == -1 || readn == 0)
			return (readn == -1 ? -1 : 1);
		if (expand_memory_size(line, &total_size) == -1)
			return (-1);
	}
	setting_material(&material);
	return (1);
}
