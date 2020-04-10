/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kycho <kycho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 21:39:35 by kycho             #+#    #+#             */
/*   Updated: 2020/04/11 02:53:16 by kycho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	idx;

	ptr = (char *)malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	idx = 0;
	while (idx < count * size)
	{
		((unsigned char *)ptr)[idx] = (unsigned char)0;
		idx++;
	}
	return (ptr);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t idx;

	idx = 0;
	while (idx < n)
	{
		((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
		if (((unsigned char *)src)[idx] == (unsigned char)c)
			return (dst + idx + 1);
		idx++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != 0)
		len++;
	return (len);
}
