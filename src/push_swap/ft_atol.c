/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:07:36 by erde-la-          #+#    #+#             */
/*   Updated: 2024/11/25 12:08:09 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *nptr)
{
	char	*nptr_cpy;
	long	result;
	long	parity;

	nptr_cpy = (char *)nptr;
	while ((*nptr_cpy >= 9 && *nptr_cpy <= 13) || *nptr_cpy == ' ')
		nptr_cpy++;
	parity = 1;
	if (*nptr_cpy == '-' || *nptr_cpy == '+')
	{
		if (*nptr_cpy == '-')
			parity *= -1;
		nptr_cpy++;
	}
	result = 0;
	while (*nptr_cpy && (*nptr_cpy >= '0' && *nptr_cpy <= '9'))
	{
		result *= 10;
		result += (*nptr_cpy - 48);
		nptr_cpy++;
	}
	return (result * parity);
}
