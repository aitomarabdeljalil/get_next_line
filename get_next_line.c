/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:52:24 by aait-oma          #+#    #+#             */
/*   Updated: 2021/12/17 11:03:35 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "get_next_line.h"

static ssize_t	ft_n_indexof(char *b, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (b[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

typedef struct s_buffer {
	char	buffer[BUFFER_SIZE];
	size_t	len;
	size_t	start;
}	t_buffer;

static char	*ft_check_next_line(int fd)
{
	static t_buffer	buffer;
	char			*result;
	ssize_t			readc;
	ssize_t			i;

	if (buffer.len == 0)
	{
		buffer.start = 0;
		readc = read(fd, buffer.buffer, BUFFER_SIZE);
		if (readc <= 0)
			return (NULL);
		buffer.len = readc;
	}
	i = ft_n_indexof(buffer.buffer + buffer.start, '\n', buffer.len);
	if (i == -1)
	{
		result = ft_strndup(buffer.buffer + buffer.start, buffer.len);
		buffer.len = 0;
		return (result);
	}
	result = ft_strndup(buffer.buffer + buffer.start, i + 1);
	buffer.start += i + 1;
	buffer.len -= i + 1;
	return (result);
}

char	*get_next_line(int fd)
{
	char		*a;
	char		*b;
	char		*tmp;
	size_t		len;

	a = ft_check_next_line(fd);
	b = NULL;
	while (a)
	{
		if (b)
		{
			tmp = a;
			a = ft_strjoin(b, tmp);
			free(tmp);
			free(b);
		}
		len = ft_strlen(a);
		if (len && a[len - 1] == '\n')
			return (a);
		b = a;
		a = ft_check_next_line(fd);
	}
	return (b);
}
