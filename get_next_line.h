/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:02:28 by kycho             #+#    #+#             */
/*   Updated: 2020/04/11 02:50:04 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

typedef struct	s_gnl_material
{
	int			value_to_print_exist;
	char		buffer[BUFFER_SIZE];
	size_t		start_idx;
	size_t		last_idx;
}				t_gnl_material;

int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
size_t			ft_strlen(const char *s);

#endif
