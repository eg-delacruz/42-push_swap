/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:48:44 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 15:05:05 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"
#include "../../includes/push_swap.h"

static int	do_rot_op(char *line, t_state **state)
{
	if (!ft_strncmp(line, "ra\n", ft_strlen(line)))
		ft_ch_rot(&((*state)->stack_a), (*state)->size_a);
	else if (!ft_strncmp(line, "rb\n", ft_strlen(line)))
		ft_ch_rot(&((*state)->stack_b), (*state)->size_b);
	else if (!ft_strncmp(line, "rr\n", ft_strlen(line)))
		ft_ch_rot_both(state);
	else if (!ft_strncmp(line, "rra\n", ft_strlen(line)))
		ft_ch_r_rot(&((*state)->stack_a), (*state)->size_a);
	else if (!ft_strncmp(line, "rrb\n", ft_strlen(line)))
		ft_ch_r_rot(&((*state)->stack_b), (*state)->size_b);
	else if (!ft_strncmp(line, "rrr\n", ft_strlen(line)))
		ft_ch_r_rot_both(state);
	else
		return (0);
	return (1);
}

static int	do_op(char *line, t_state **state)
{
	if (!ft_strncmp(line, "sa\n", ft_strlen(line)))
		ft_ch_rot_top(&((*state)->stack_a), (*state)->size_a);
	else if (!ft_strncmp(line, "sb\n", ft_strlen(line)))
		ft_ch_rot_top(&((*state)->stack_b), (*state)->size_b);
	else if (!ft_strncmp(line, "ss\n", ft_strlen(line)))
		ft_ch_rot_both_top(state);
	else if (!ft_strncmp(line, "pa\n", ft_strlen(line)))
		ft_ch_pa(state);
	else if (!ft_strncmp(line, "pb\n", ft_strlen(line)))
		ft_ch_pb(state);
	else
		return (do_rot_op(line, state));
	return (1);
}

static int	ft_checker(t_state **state)
{
	int		no_op_match;
	char	*line;

	no_op_match = 1;
	line = get_next_line(0);
	while (line)
	{
		if (!do_op(line, state))
			no_op_match = 0;
		free(line);
		line = get_next_line(0);
	}
	free(line);
	if (!no_op_match)
		return (0);
	if (!ft_is_sorted((*state)->stack_a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	return (1);
}

int	main(int argc, char *args[])
{
	t_stack	*stack_a;
	t_state	*state;

	stack_a = NULL;
	stack_a = parse_data(argc, args);
	if (!stack_a)
		return (-1);
	state = ft_init_state(stack_a);
	if (!state)
		return (-1);
	if (!ft_checker(&state))
		ft_puterror();
	ft_stateclear(&state);
	return (0);
}
