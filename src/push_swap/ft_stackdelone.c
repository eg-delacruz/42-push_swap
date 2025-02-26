/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:54:22 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:52 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->content)
		free(stack->content);
	stack->content = NULL;
	free(stack);
	stack = NULL;
}
