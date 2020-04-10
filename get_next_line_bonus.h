/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 22:02:28 by kycho             #+#    #+#             */
/*   Updated: 2020/04/11 02:52:05 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# ifndef FD_NUMBER
#  define FD_NUMBER 256
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
