/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:27 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:19 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
- Get target of b nodes in a
	+ Target: bigger closest number to b node
	+ If no bigger number in a, target is smallest value in a
*/

static void	ft_b_to_a_target(t_stack *b_node, t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*target;

	tmp = *stack_a;
	target = ft_get_max(stack_a);
	while (tmp)
	{
		if (*tmp->content < *target->content
			&& *tmp->content > *b_node->content)
			target = tmp;
		tmp = tmp->next;
	}
	if (*b_node->content > *target->content)
		target = ft_get_min(stack_a);
	b_node->target_node = target;
}

void	ft_sort_b_to_a(t_state **state)
{
	t_stack	*b_node;
	int		a_size;

	b_node = (*state)->stack_b;
	a_size = (*state)->size_a;
	ft_idx_stack(&((*state)->stack_a));
	ft_idx_stack(&((*state)->stack_b));
	ft_b_to_a_target(b_node, &((*state)->stack_a));
	ft_set_above_med(&((*state)->stack_a), (*state)->size_a);
	ft_node_to_top(&((*state)->stack_a), b_node->target_node, a_size, 'a');
	ft_pa(state);
}
