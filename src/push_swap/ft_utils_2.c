/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:57 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:30 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_get_cheapest(t_stack **stack)
{
	t_stack	*cheapest;
	t_stack	*tmp;

	cheapest = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->cheapest_node)
			cheapest = tmp;
		tmp = tmp->next;
	}
	if (!cheapest->cheapest_node)
		return (NULL);
	return (cheapest);
}

void	ft_set_above_med(t_stack **stack, int size)
{
	int		median;
	t_stack	*tmp;

	if (size == 0)
		return ;
	median = size / 2;
	tmp = *stack;
	while (tmp)
	{
		tmp->above_median = 0;
		if (size % 2 == 0 && median > tmp->idx)
			tmp->above_median = 1;
		else if (size % 2 != 0 && median >= tmp->idx)
			tmp->above_median = 1;
		tmp = tmp->next;
	}
}
