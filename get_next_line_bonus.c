/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:52:24 by aait-oma          #+#    #+#             */
/*   Updated: 2021/12/01 20:57:27 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "get_next_line_bonus.h"

typedef struct s_file {
	int				fd;
	char			buffer[BUFFER_SIZE];
	size_t			len;
	size_t			start;
	struct s_file	*next;
}	t_file;

t_file	*ft_file_get_or_create(t_file **lst, int fd)
{
	t_file	*f;

	f = *lst;
	while (f && f->fd != fd)
		f = f->next;
	if (f != NULL)
		return (f);
	f = malloc(sizeof(t_file));
	if (f == NULL)
		return (NULL);
	f->fd = fd;
	f->start = 0;
	f->len = 0;
	f->next = *lst;
	*lst = f;
	return (f);
}

void	ft_file_free(t_file **lst, int fd)
{
	t_file	*p;
	t_file	*c;

	p = NULL;
	c = *lst;
	while (c && c->fd != fd)
	{
		p = c;
		c = c->next;
	}
	if (c != NULL)
	{
		if (p == NULL)
			*lst = c->next;
		else
			p->next = c->next;
		free(c);
	}
}

static ssize_t	fill_buff(t_file *file)
{
	ssize_t	readc;

	file->start = 0;
	readc = read(file->fd, file->buffer, BUFFER_SIZE);
	file->len = readc;
	return (readc);
}

static char	*ft_check_next_line(int fd)
{
	static t_file	*lst;
	t_file			*file;
	char			*result;
	ssize_t			i;

	file = ft_file_get_or_create(&lst, fd);
	if (file == NULL)
		return (NULL);
	if (file->len == 0 && fill_buff(file) <= 0)
	{
		ft_file_free(&lst, fd);
		return (NULL);
	}
	i = ft_n_indexof(file->buffer + file->start, '\n', file->len);
	if (i == -1)
		i = file->len - 1;
	result = ft_strndup(file->buffer + file->start, i + 1);
	file->start += i + 1;
	file->len -= i + 1;
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
			a = ft_strjoin(b, a);
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
