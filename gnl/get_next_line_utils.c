/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:14:28 by erde-la-          #+#    #+#             */
/*   Updated: 2024/10/16 10:40:51 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	char	*start_of_str;

	if (!s1)
		return (NULL);
	joined_str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	start_of_str = joined_str;
	while (*s1)
	{
		*joined_str = *s1;
		joined_str++;
		s1++;
	}
	while (*s2)
	{
		*joined_str = *s2;
		joined_str++;
		s2++;
	}
	*joined_str = '\0';
	return (start_of_str);
}

char	*gnl_strchr(const char *s, int c)
{
	c = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = gnl_strlen(src);
	if (size != 0)
	{
		i = 0;
		while (src [i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

void	gnl_free(void **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}
