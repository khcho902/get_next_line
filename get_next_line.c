/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:04:43 by kycho             #+#    #+#             */
/*   Updated: 2020/03/27 16:10:11 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

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
		if(!(*line = calloc(BUFFER_SIZE + 1, sizeof(char))))  // 바꿔야함
			return (-1);
		*total_size = BUFFER_SIZE + 1;
	}
	else 
	{
		if (!(new_line = calloc(*total_size + BUFFER_SIZE, sizeof(char))))  // 내꺼로 바꿔야함
		{
			free(*line);
			return (-1);
		}
		memccpy(new_line, *line, '\0', *total_size);  // 바꿔야함 
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

	line_idx = strlen(*line);

//	printf("line_idx : %ld\n", line_idx);

	while (material->start_idx <= material->last_idx)
	{
		
//		printf("while start ---------\n");
//		printf("line_idx : %ld\n", line_idx);
//		printf("line : %s\n", *line);

		ch = material->buffer[material->start_idx];
//		printf("ch : %c\n", ch);
		if (ch == '\n')
		{
//			printf("ch == nn?? \n");
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


void	printStatus(t_gnl_material *material, char **line, size_t total_size)
{
	printf("=== material ===\n");
	printf("value_to_print_exist : %d\n", material->value_to_print_exist);
	printf("buffer : ");
	for(int i = 0; i < BUFFER_SIZE; i++)
	{
		printf("%c", material->buffer[i]);
	}
	printf("\n");
	printf("start_idx : %ld\n", material->start_idx);
	printf("last_idx : %ld\n\n", material->last_idx);

	printf("===== line  ===\n");
	printf("total_size : %ld\n", total_size);
	printf("line : %s\n", *line);

	printf("------------------------------\n");
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

	
//	printStatus(&material, line, total_size);
	
//	copy_buffer(line, &material);
	
//	printStatus(&material, line, total_size);
	

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
