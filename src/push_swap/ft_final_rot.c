/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:19:01 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:44:02 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_final_rot(t_state **state)
{
	t_stack	*stack_a;
	t_stack	*min;

	stack_a = (*state)->stack_a;
	ft_idx_stack(&stack_a);
	ft_set_above_med(&stack_a, (*state)->size_a);
	min = ft_get_min(&stack_a);
	ft_node_to_top(&((*state)->stack_a), min, (*state)->size_a, 'a');
}
