/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:44:58 by erde-la-          #+#    #+#             */
/*   Updated: 2025/01/13 13:30:45 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ft_sort_two(t_stack	**stack_a, int stack_size)
{
	ft_rot_top(stack_a, stack_size, 'a');
}

void	ft_sort_three(t_stack **stack, int size, char c)
{
	t_stack	*max;

	ft_idx_stack(stack);
	max = ft_get_max(stack);
	if (max->idx == 0)
		ft_rot(stack, size, c);
	else if (max->idx == 1)
		ft_r_rot(stack, size, c);
	if (!ft_is_sorted(*stack))
		ft_rot_top(stack, size, c);
}

void	ft_mech_turk(t_state **state)
{
	while ((*state)->size_a > 3 && (*state)->size_b < 2)
		ft_pb(state);
	while ((*state)->size_a > 3)
		ft_sort_a_to_b(state);
	ft_sort_three(&((*state)->stack_a), (*state)->size_a, 'a');
	while ((*state)->size_b > 0)
		ft_sort_b_to_a(state);
	ft_final_rot(state);
}

int	ft_sort(t_stack *stack)
{
	t_state	*state;

	state = ft_init_state(stack);
	if (!state)
		return (-1);
	if (state->size_a <= 2)
		ft_sort_two(&(state->stack_a), state->size_a);
	else if (state->size_a == 3)
		ft_sort_three(&(state->stack_a), state->size_a, 'a');
	else
		ft_mech_turk(&state);
	ft_stateclear(&state);
	return (0);
}
