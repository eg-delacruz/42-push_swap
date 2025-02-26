/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:31:01 by erde-la-          #+#    #+#             */
/*   Updated: 2025/01/13 11:14:33 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static size_t	count_str(int argc, char *args[])
{
	int		i;
	int		j;
	size_t	str_count;

	str_count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (args[i][j])
		{
			while (args[i][j] && args[i][j] == ' ')
				j++;
			if (args[i][j])
			{
				j++;
				str_count++;
			}
			while (args[i][j] && args[i][j] != ' ')
				j++;
		}
		i++;
	}
	return (str_count);
}

static char	**get_arr(int argc, char *args[])
{
	char	**arr;
	int		number_count;

	arr = NULL;
	number_count = count_str(argc, args);
	if (!number_count)
	{
		ft_puterror();
		return (NULL);
	}
	arr = ft_calloc(sizeof(char *), (number_count + 1));
	if (!arr)
		return (arr = NULL);
	return (fill_arr(argc, args, &arr));
}

static t_stack	*fill_stack(char **arr, t_stack **stack)
{
	int		i;
	int		*result;
	t_stack	*node;

	node = NULL;
	i = 0;
	while (arr[++i])
	{
		result = malloc(sizeof(int));
		if (!result)
			return (NULL);
		*result = ft_atoi(arr[i]);
		if (!check_doubles(*result, stack))
			return (free(result), NULL);
		node = ft_stacknew(result);
		if (!node)
			return (free(result), NULL);
		ft_stack_add_back(stack, node);
	}
	return (*stack);
}

static t_stack	*validate_arr(char **arr)
{
	t_stack	*stack;
	t_stack	*check;
	int		i;
	int		*result;

	i = 0;
	while (arr[i])
	{
		if (!allow_char(arr[i]) || !check_symbols(arr[i]))
			return (NULL);
		if (!check_limits(arr[i]))
			return (NULL);
		i++;
	}
	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	*result = ft_atoi(arr[0]);
	stack = ft_stacknew(result);
	if (!stack)
		return (free(result), NULL);
	check = fill_stack(arr, &stack);
	if (!check)
		return (ft_stackclear(&stack), NULL);
	return (stack);
}

t_stack	*parse_data(int argc, char *args[])
{
	char	**arr;
	t_stack	*stack;

	arr = NULL;
	stack = NULL;
	if (argc < 2)
		return (NULL);
	arr = get_arr(argc, args);
	if (!arr)
		return (NULL);
	stack = validate_arr(arr);
	ft_free_strs_arr(&arr);
	return (stack);
}
