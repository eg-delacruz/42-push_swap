/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:42 by erde-la-          #+#    #+#             */
/*   Updated: 2024/10/24 10:01:43 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nil(int fd)
{
	if (write(fd, &"(nil)", 5) != 5)
		return (-1);
	return (5);
}

static int	ft_check_base_error(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || len == 1)
		return (1);
	while (str[i])
	{
		if (str[i] <= ' ' || str[i] == 127 || str[i] == '+' || str[i] == '-')
			return (1);
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_putnbr_base(uintptr_t n, char *b, uintptr_t b_len, int tmp)
{
	int	count;

	count = 0;
	if (ft_check_base_error(b, b_len) == 0)
	{
		if (n < b_len)
		{
			tmp = ft_putchar_fd_custom(b[n], 1);
			if (tmp < 0)
				return (-1);
			count += tmp;
		}
		if (n >= b_len)
		{
			tmp = ft_putnbr_base(n / b_len, b, b_len, tmp);
			if (tmp < 0)
				return (-1);
			count += tmp;
			tmp = ft_putnbr_base(n % b_len, b, b_len, tmp);
			if (tmp < 0)
				return (-1);
			count += tmp;
		}
	}
	return (count);
}

int	ft_putptr(void *ptr, int fd)
{
	int			count;
	uintptr_t	pointer;
	uintptr_t	base_len;
	char		*base;
	int			tmp;

	if (ptr == NULL)
		return (ft_put_nil(fd));
	count = 0;
	tmp = 0;
	pointer = (uintptr_t)ptr;
	base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (write(fd, &"0x", 2) != 2)
		return (-1);
	count += 2;
	count += ft_putnbr_base(pointer, base, base_len, tmp);
	return (count);
}
