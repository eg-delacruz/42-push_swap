/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsign.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:27 by erde-la-          #+#    #+#             */
/*   Updated: 2024/10/24 10:01:29 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsign(unsigned int nb, int fd)
{
	int	count;
	int	tmp;

	count = 0;
	tmp = 0;
	if (nb > 9)
	{
		tmp = ft_putnbr_fd_custom(nb / 10, fd);
		if (tmp < 0)
			return (-1);
		count += tmp;
		tmp = ft_putchar_fd_custom(((nb % 10) + 48), fd);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	else
	{
		tmp = ft_putchar_fd_custom((nb + 48), fd);
		if (tmp < 0)
			return (-1);
		count += tmp;
	}
	return (count);
}
