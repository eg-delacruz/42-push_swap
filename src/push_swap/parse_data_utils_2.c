/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:32:57 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:17 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_doubles(int number, t_stack **stack)
{
	t_stack	*curr_stack;

	if (!stack || !*stack)
	{
		ft_puterror();
		return (0);
	}
	curr_stack = *stack;
	while (curr_stack)
	{
		if (number == *(int *)curr_stack->content)
		{
			ft_puterror();
			return (0);
		}
		curr_stack = curr_stack->next;
	}
	return (1);
}
