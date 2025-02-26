/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:17 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:22 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/*
- Get target of a nodes in b
	+ Target: smallest closest number to a node
	+ If no smaller number in b, target is largest value
*/
static void	ft_a_to_b_target(t_state **state)
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_stack	*target;
	t_stack	*b_head;

	stk_a = (*state)->stack_a;
	stk_b = (*state)->stack_b;
	b_head = (*state)->stack_b;
	while (stk_a)
	{
		target = ft_get_min(&b_head);
		while (stk_b)
		{
			if (*stk_b->content > *target->content
				&& *stk_b->content < *stk_a->content)
				target = stk_b;
			stk_b = stk_b->next;
		}
		if (*target->content > *stk_a->content)
			target = ft_get_max(&b_head);
		stk_a->target_node = target;
		stk_b = b_head;
		stk_a = stk_a->next;
	}
}

static void	ft_set_a_cost(t_state **state)
{
	t_stack	*a;
	int		shortest;

	a = (*state)->stack_a;
	while (a)
	{
		a->push_cost = ft_med_cost(a, (*state)->size_a);
		a->push_cost += ft_med_cost(a->target_node, (*state)->size_b);
		if (a->above_median && a->target_node->above_median)
		{
			shortest = a->target_node->idx;
			if (shortest > a->idx)
				shortest = a->idx;
			a->push_cost -= shortest;
		}
		else if (!(a->above_median) && !(a->target_node->above_median))
		{
			shortest = ((*state)->size_b) - (a->target_node->idx);
			if (shortest > ((*state)->size_a) - (a->idx))
				shortest = ((*state)->size_a) - a->idx;
			a->push_cost -= shortest;
		}
		a = a->next;
	}
}

static void	ft_move_a_to_b(t_state **state)
{
	t_stack	*cheapest;
	t_stack	*target;

	cheapest = ft_get_cheapest(&((*state)->stack_a));
	target = cheapest->target_node;
	ft_move_both_top(state, cheapest, target);
	ft_node_to_top(&((*state)->stack_a), cheapest, ((*state)->size_a), 'a');
	ft_node_to_top(&((*state)->stack_b), target, ((*state)->size_b), 'b');
	ft_pb(state);
}

void	ft_sort_a_to_b(t_state **state)
{
	ft_a_to_b_target(state);
	ft_idx_stack(&((*state)->stack_a));
	ft_idx_stack(&((*state)->stack_b));
	ft_set_a_cost(state);
	ft_set_cheapest(&((*state)->stack_a));
	ft_move_a_to_b(state);
}
