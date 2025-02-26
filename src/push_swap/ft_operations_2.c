/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:56 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:33 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rot(t_stack **stack, int size, char c)
{
	t_stack	*last;

	if (!stack || !*stack || size <= 1)
		return ;
	last = ft_stacklast(*stack);
	if (!last)
		return ;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	ft_r_rot(t_stack **stack, int size, char c)
{
	t_stack	*last;

	if (!stack || !*stack || size <= 1)
		return ;
	last = ft_stacklast(*stack);
	if (!last)
		return ;
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	last->next->prev = last;
	*stack = last;
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

void	ft_r_rot_both(t_state **state)
{
	t_state	*tmp_state;

	tmp_state = *state;
	ft_r_rot(&(tmp_state->stack_a), tmp_state->size_a, 'r');
	ft_r_rot(&(tmp_state->stack_b), tmp_state->size_b, 'r');
	ft_printf("rrr\n");
}
