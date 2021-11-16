/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get__next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-oma <aait-oma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:11:38 by aait-oma          #+#    #+#             */
/*   Updated: 2021/11/16 23:55:53 by aait-oma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = dst;
	psrc = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (n--)
		*(pdst++) = *(psrc++);
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *src, size_t size)
{
	char	*copy;

	copy = malloc(size + 1);
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, src, size + 1);
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s = malloc(len_s1 + len_s2 + 1);
	if (s != NULL)
	{
		ft_memcpy(s, s1, len_s1 + 1);
		ft_memcpy(s + len_s1, s2, len_s2 + 1);
	}
	return (s);
}
