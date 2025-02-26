/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:13:26 by erde-la-          #+#    #+#             */
/*   Updated: 2024/10/17 14:22:54 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_raw_str(int fd, char *buffer, char *rem_str)
{
	char		*tmp;
	ssize_t		b_read;

	if (gnl_strchr(rem_str, '\n'))
		return (rem_str);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		tmp = rem_str;
		rem_str = gnl_strjoin(tmp, buffer);
		if (!rem_str)
			return (gnl_free((void **)&tmp), NULL);
		gnl_free((void **)&tmp);
		if (gnl_strchr(buffer, '\n'))
			break ;
	}
	return (rem_str);
}

static char	*ft_clean_str(char *raw_line)
{
	char	*clean_str;
	int		i;

	i = 0;
	while (raw_line[i] && raw_line[i] != '\n')
		i++;
	if (raw_line[i] == '\0' && raw_line[i] != '\n')
		return (raw_line);
	clean_str = malloc(sizeof(char) * (i + 2));
	if (!clean_str)
		return (gnl_free((void **)&raw_line), NULL);
	i = 0;
	while (raw_line[i] != '\n')
	{
		clean_str[i] = raw_line[i];
		i++;
	}
	clean_str[i] = '\n';
	clean_str[++i] = '\0';
	return (gnl_free((void **)&raw_line), clean_str);
}

static char	*ft_remain_str(char *raw_line, char *old_rem_str)
{
	char	*rem_str;
	int		i;
	size_t	str_len;

	i = 0;
	while (raw_line[i] != '\n' && raw_line[i])
		i++;
	if (raw_line[i] == '\0')
	{
		rem_str = malloc(1);
		if (!rem_str)
			return (gnl_free((void **)&raw_line), NULL);
		rem_str[0] = '\0';
		return (rem_str);
	}
	i++;
	str_len = gnl_strlen(raw_line + i);
	rem_str = malloc(str_len + 1);
	if (!rem_str)
	{
		gnl_free((void **)&old_rem_str);
		return (gnl_free((void **)&raw_line), NULL);
	}
	gnl_strlcpy(rem_str, raw_line + i, str_len + 1);
	return (rem_str);
}

static char	*ft_init_check(char *rem_str, int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (gnl_free((void **)&rem_str), NULL);
	if (rem_str == NULL)
	{
		rem_str = malloc(1);
		if (!rem_str)
			return (NULL);
		rem_str[0] = '\0';
	}
	return (rem_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*rem_str;

	rem_str = ft_init_check(rem_str, fd);
	if (!rem_str)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (gnl_free((void **)&rem_str), NULL);
	if (rem_str == NULL)
		return (gnl_free((void **)&buffer), NULL);
	line = ft_raw_str(fd, buffer, rem_str);
	if (line == NULL)
		return (gnl_free((void **)&buffer), gnl_free((void **)&rem_str), NULL);
	gnl_free((void **)&buffer);
	if (*line == '\0')
		return (gnl_free((void **)&rem_str), line = NULL, line);
	rem_str = ft_remain_str(line, rem_str);
	if (!rem_str)
		return (NULL);
	line = ft_clean_str(line);
	if (!line)
		return (gnl_free((void **)&rem_str), NULL);
	return (line);
}
