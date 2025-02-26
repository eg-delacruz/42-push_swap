/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:13:51 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:44:06 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (*stack->content > *stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}
