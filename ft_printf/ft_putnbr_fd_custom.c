/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:48:46 by erde-la-          #+#    #+#             */
/*   Updated: 2024/09/30 09:55:55 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*Does exactly the same as original putnbr, 
but returns the count of printed bytes and 
handles possible write() errors*/
int	ft_putnbr_fd_custom(int n, int fd);

static int	ft_print_min(int fd)
{
	return (write(fd, &"-2147483648", 11));
}

static int	ft_handle_neg(int *n, int *count, int fd)
{
	int	tmp;

	tmp = ft_putchar_fd_custom('-', fd);
	if (tmp < 0)
		return (-1);
	*count += tmp;
	*n = *n * -1;
	tmp = ft_putnbr_fd_custom(*n, fd);
	if (tmp < 0)
		return (-1);
	*count += tmp;
	return (0);
}

static int	ft_handle_last_digit(int n, int *count, int fd)
{
	int	tmp;

	tmp = ft_putnbr_fd_custom(n / 10, fd);
	if (tmp < 0)
		return (-1);
	*count += tmp;
	tmp = ft_putchar_fd_custom(((n % 10) + 48), fd);
	if (tmp < 0)
		return (-1);
	*count += tmp;
	return (0);
}

static int	ft_handle_digit(int n, int *count, int fd)
{
	int	tmp;

	tmp = ft_putchar_fd_custom((n + 48), fd);
	if (tmp < 0)
		return (-1);
	*count += tmp;
	return (0);
}

int	ft_putnbr_fd_custom(int n, int fd)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_print_min(fd));
	else if (n < 0)
	{
		if (ft_handle_neg(&n, &count, fd) < 0)
			return (-1);
	}
	else if (n > 9)
	{
		if (ft_handle_last_digit(n, &count, fd) < 0)
			return (-1);
	}
	else
	{
		if (ft_handle_digit(n, &count, fd) < 0)
			return (-1);
	}
	return (count);
}
