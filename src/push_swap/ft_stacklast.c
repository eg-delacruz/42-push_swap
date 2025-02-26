/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:06:13 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:46 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *stack)
{
	size_t	stack_len;

	stack_len = ft_stacksize(stack);
	while (stack_len)
	{
		if (stack_len == 1)
			return (stack);
		stack = stack->next;
		stack_len--;
	}
	return (stack);
}
