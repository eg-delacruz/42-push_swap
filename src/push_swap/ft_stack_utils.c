/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:41 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:55 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_get_max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	max = tmp;
	while (tmp)
	{
		if (*tmp->content > *max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*ft_get_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = tmp;
	while (tmp)
	{
		if (*tmp->content < *min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	ft_idx_stack(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->idx = i;
		i++;
		tmp = tmp->next;
	}
}

void	ft_move_both_top(t_state **state, t_stack *a, t_stack *b)
{
	t_stack	*top_a;
	t_stack	*top_b;

	top_a = (*state)->stack_a;
	top_b = (*state)->stack_b;
	if (a->above_median && b->above_median)
	{
		while (*top_a->content != *a->content && *top_b->content != *b->content)
		{
			ft_rot_both(state);
			top_a = (*state)->stack_a;
			top_b = (*state)->stack_b;
		}
	}
	if (!(a->above_median) && !(b->above_median))
	{
		while (*top_a->content != *a->content && *top_b->content != *b->content)
		{
			ft_r_rot_both(state);
			top_a = (*state)->stack_a;
			top_b = (*state)->stack_b;
		}
	}
}

void	ft_node_to_top(t_stack **stack, t_stack *node, int size, char c)
{
	t_stack	*top;

	top = *stack;
	if (node->above_median)
	{
		while (top->content != node->content)
		{
			ft_rot(stack, size, c);
			top = *stack;
		}
	}
	if (!(node->above_median))
	{
		while (top->content != node->content)
		{
			ft_r_rot(stack, size, c);
			top = *stack;
		}
	}
}
