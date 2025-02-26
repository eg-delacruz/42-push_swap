/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:14:36 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:41 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rot_top(t_stack **stack, int size, char c)
{
	t_stack	*current_0;
	t_stack	*current_1;

	if (size <= 1)
		return ;
	current_0 = *stack;
	current_1 = current_0->next;
	*stack = current_1;
	current_1->prev = NULL;
	current_0->next = current_1->next;
	if (current_1->next)
		current_1->next->prev = current_0;
	current_1->next = current_0;
	current_0->prev = current_1;
	if (c == 'a' || c == 'b')
		ft_printf("s%c\n", c);
}

void	ft_rot_both_top(t_state **state)
{
	t_state	*tmp_state;

	tmp_state = *state;
	ft_rot_top(&(tmp_state->stack_a), tmp_state->size_a, 's');
	ft_rot_top(&(tmp_state->stack_b), tmp_state->size_b, 's');
	ft_printf("ss\n");
}

void	ft_pb(t_state **state)
{
	t_stack	*node;
	t_state	*tmp_state;

	tmp_state = *state;
	if (tmp_state->size_a < 1)
		return ;
	node = tmp_state->stack_a;
	tmp_state->stack_a = tmp_state->stack_a->next;
	if (tmp_state->stack_a != NULL)
		tmp_state->stack_a->prev = NULL;
	node->next = tmp_state->stack_b;
	ft_stack_add_top(&(tmp_state->stack_b), node);
	tmp_state->size_a--;
	tmp_state->size_b++;
	ft_printf("pb\n");
}

void	ft_pa(t_state **state)
{
	t_stack	*node;
	t_state	*tmp_state;

	tmp_state = *state;
	if (tmp_state->size_b < 1)
		return ;
	node = tmp_state->stack_b;
	tmp_state->stack_b = tmp_state->stack_b->next;
	if (tmp_state->stack_b != NULL)
		tmp_state->stack_b->prev = NULL;
	node->next = tmp_state->stack_a;
	ft_stack_add_top(&(tmp_state->stack_a), node);
	tmp_state->size_a++;
	tmp_state->size_b--;
	ft_printf("pa\n");
}

void	ft_rot_both(t_state **state)
{
	t_state	*tmp_state;

	tmp_state = *state;
	ft_rot(&(tmp_state->stack_a), tmp_state->size_a, 'r');
	ft_rot(&(tmp_state->stack_b), tmp_state->size_b, 'r');
	ft_printf("rr\n");
}
