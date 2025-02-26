/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:12 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/04 12:42:56 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_cases(char c, va_list args, int fd)
{
	if (c == '%')
		return (ft_putchar_fd_custom(c, fd));
	else if (c == 'c')
		return (ft_putchar_fd_custom(va_arg(args, int), fd));
	else if (c == 's')
		return (ft_putstr_fd_custom(va_arg(args, char *), fd));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_fd_custom(va_arg(args, int), fd));
	else if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(args, int), c));
	else if (c == 'u')
		return (ft_put_unsign(va_arg(args, unsigned int), fd));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *), fd));
	else if (c == '\0')
		return (-1);
	else
		return (0);
}

static void	ft_print_loop(const char *s, va_list args, int *count, int tmp)
{
	while (*s)
	{
		if (*s != '%')
		{
			tmp = ft_putchar_fd_custom(*s, 1);
			if (tmp < 0)
			{
				*count = -1;
				break ;
			}
			*count += tmp;
		}
		else if (*s == '%')
		{
			tmp = ft_print_cases(*(++s), args, 1);
			if (tmp < 0)
			{
				*count = -1;
				break ;
			}
			*count += tmp;
		}
		s++;
	}
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		tmp;
	va_list	args;

	tmp = 0;
	count = 0;
	va_start(args, s);
	ft_print_loop(s, args, &count, tmp);
	va_end(args);
	return (count);
}
