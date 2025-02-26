/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:56:51 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:42:08 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char *args[])
{
	t_stack	*stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = parse_data(argc, args);
		if (!stack_a)
			return (-1);
		if (!ft_is_sorted(stack_a))
			return (ft_sort(stack_a));
		ft_stackclear(&stack_a);
	}
	return (0);
}
