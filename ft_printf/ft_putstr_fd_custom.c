/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_custom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:32:17 by erde-la-          #+#    #+#             */
/*   Updated: 2024/10/24 10:13:40 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnullstr(void)
{
	if (write(1, &"(null)", 6) != 6)
		return (-1);
	return (6);
}

int	ft_putstr_fd_custom(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return (ft_putnullstr());
	i = 0;
	while (s[i])
	{
		if (ft_putchar_fd_custom(s[i], fd) < 0)
			return (-1);
		i++;
	}
	return (i);
}
