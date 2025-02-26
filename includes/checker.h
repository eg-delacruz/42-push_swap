/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:31:20 by erde-la-          #+#    #+#             */
/*   Updated: 2025/01/13 15:04:28 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "./push_swap.h"

# include <stddef.h>
# include <stdio.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/* Stack functions */
t_stack	*ft_stacknew(int *content);
void	ft_stackdelone(t_stack *stack);
void	ft_stackclear(t_stack **stack);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stack_add_top(t_stack **stack, t_stack *new);
void	ft_stack_add_back(t_stack **stack, t_stack *new);

/* Parse functions */
t_stack	*parse_data(int argc, char *args[]);
int		allow_char(char *s);
int		check_symbols(char *s);
int		check_limits(char *str);
long	ft_atol(const char *nptr);
char	**fill_arr(int argc, char *args[], char ***arr);
int		check_doubles(int number, t_stack **stack);

/* Cleaning functions */
void	*ft_free_strs_arr(char ***arr);
void	ft_stateclear(t_state **state);

/* Opertions without ft_print */
void	ft_ch_rot_top(t_stack **stack, int size);
void	ft_ch_rot_both_top(t_state **state);
void	ft_ch_pb(t_state **state);
void	ft_ch_pa(t_state **state);
void	ft_ch_rot(t_stack **stack, int size);
void	ft_ch_rot_both(t_state **state);
void	ft_ch_r_rot(t_stack **stack, int size);
void	ft_ch_r_rot_both(t_state **state);

/* Sorting process */
int		ft_sort(t_stack *stack);
void	ft_sort_a_to_b(t_state **state);
void	ft_sort_b_to_a(t_state **state);
void	ft_final_rot(t_state **state);

/* Stack utils */
void	ft_move_both_top(t_state **state, t_stack *a, t_stack *b);

/* Utils */
t_state	*ft_init_state(t_stack *stack_a);
int		ft_is_sorted(t_stack *stack);
void	ft_print_stack(t_stack **stack, int med, int cheapest, int cost);
void	ft_print_state(t_state **state);

/* Error handling */
void	ft_puterror(void);

#endif
