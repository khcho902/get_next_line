/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:04:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/29 01:37:19 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	expand_memory_size(char **line, size_t *total_size)
{
	char *new_line;

	if (*total_size == 0 && *line == NULL)
	{
		if(!(*line = ft_calloc(BUFFER_SIZE + 1, sizeof(char))))
			return (-1);
		*total_size = BUFFER_SIZE + 1;
	}
	else 
	{
		new_line = ft_calloc(*total_size + BUFFER_SIZE, sizeof(char));
		if (new_line == NULL)
		{
			free(*line);
			return (-1);
		}
		ft_memccpy(new_line, *line, '\0', *total_size);
		free(*line);
		*line = new_line;
		*total_size += BUFFER_SIZE;
	}
	return (1);
}

int	copy_buffer(char **line, t_gnl_material *material)
{
	char ch;
	size_t line_idx;

	line_idx = ft_strlen(*line);
	while (material->start_idx <= material->last_idx)
	{
		ch = material->buffer[material->start_idx];
		if (ch == '\n')
		{
			if (material->start_idx == material->last_idx)
				material->value_to_print_exist = 0;
			else
				material->start_idx++;
			return (0);
		}
		(*line)[line_idx] = ch;
		line_idx++;
		material->start_idx++;
	}
	material->value_to_print_exist = 0;
	return (1); 
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
	*line = NULL;
	total_size = 0;
	if (expand_memory_size(line, &total_size) == -1)
		return (-1);
	while (copy_buffer(line, &material) == 1)
	{
		readn = read_to_buffer(fd, &material);
		if (readn == -1 || readn == 0)
			return (readn == -1 ? -1 : 1);
		if (expand_memory_size(line, &total_size) == -1)
			return (-1);
	}
	return (1);
}
