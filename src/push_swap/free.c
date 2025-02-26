/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:34:01 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:44:09 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	*ft_free_strs_arr(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return (NULL);
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
	return (NULL);
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*temp_stack;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp_stack = (*stack)->next;
		ft_stackdelone(*stack);
		*stack = temp_stack;
	}
	*stack = NULL;
}

void	ft_stateclear(t_state **state)
{
	if (!state || !*state)
		return ;
	ft_stackclear(&(*state)->stack_a);
	ft_stackclear(&(*state)->stack_b);
	free(*state);
	*state = NULL;
}
