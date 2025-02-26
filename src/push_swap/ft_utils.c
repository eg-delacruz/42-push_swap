/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:31:01 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:25 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_print_stack(t_stack **stack, int med, int cheapest, int cost)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack;
	while (tmp_stack)
	{
		ft_printf("%svalue: %d | ", YELLOW, *tmp_stack->content);
		ft_printf("%sidx: %d | ", MAGENTA, tmp_stack->idx);
		if (tmp_stack->target_node)
		{
			ft_printf("%s", YELLOW);
			ft_printf("target: %d | ", *tmp_stack->target_node->content);
		}
		if (med)
		{
			ft_printf("%s", MAGENTA);
			ft_printf("above med: %d | ", tmp_stack->above_median);
		}
		if (cheapest)
			ft_printf("%scheap_node: %d | ", YELLOW, tmp_stack->cheapest_node);
		if (cost)
			ft_printf("%spush_cost: %d", MAGENTA, tmp_stack->push_cost);
		ft_printf(" \n");
		tmp_stack = tmp_stack->next;
	}
	ft_printf("%s", RESET);
}

void	ft_print_state(t_state **state)
{
	t_stack	*tmp_stack;

	tmp_stack = (*state)->stack_a;
	ft_printf("%sA - size: %d\n", YELLOW, ((*state)->size_a));
	while (tmp_stack)
	{
		ft_printf("%d", *tmp_stack->content);
		if (tmp_stack->next)
			ft_printf(" -> ");
		tmp_stack = tmp_stack->next;
	}
	tmp_stack = (*state)->stack_b;
	ft_printf("\n-------------\nB - size: %d\n", ((*state)->size_b));
	while (tmp_stack)
	{
		ft_printf("%d", *tmp_stack->content);
		if (tmp_stack->next)
			ft_printf(" -> ");
		tmp_stack = tmp_stack->next;
	}
	ft_printf("\n%s", RESET);
}

t_state	*ft_init_state(t_stack *stack_a)
{
	t_state	*state;
	t_stack	*stack_b;

	state = (t_state *)malloc(sizeof(t_state));
	if (!state)
		return (ft_stackclear(&stack_a), NULL);
	state->stack_a = stack_a;
	stack_b = NULL;
	state->stack_b = stack_b;
	state->size_a = ft_stacksize(stack_a);
	state->size_b = ft_stacksize(stack_b);
	return (state);
}

int	ft_med_cost(t_stack *node, int size)
{
	int	cost;
	int	median;

	median = size / 2;
	node->above_median = 0;
	if (size % 2 == 0 && median > node->idx)
		node->above_median = 1;
	else if (size % 2 != 0 && median >= node->idx)
		node->above_median = 1;
	cost = node->idx;
	if (!(node->above_median))
		cost = size - node->idx;
	return (cost);
}

void	ft_set_cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current_cheapest;

	tmp = *stack;
	current_cheapest = tmp;
	while (tmp)
	{
		if (tmp->push_cost < current_cheapest->push_cost)
			current_cheapest = tmp;
		tmp->cheapest_node = 0;
		tmp = tmp->next;
	}
	tmp = *stack;
	while (tmp)
	{
		if (*tmp->content == *current_cheapest->content)
			tmp->cheapest_node = 1;
		tmp = tmp->next;
	}
}
