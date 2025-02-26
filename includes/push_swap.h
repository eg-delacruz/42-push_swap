/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:31:20 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/10 14:32:29 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
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

typedef struct s_stack
{
	int				*content;
	int				idx;
	int				above_median;
	int				cheapest_node;
	int				push_cost;
	struct s_stack	*target_node;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_state
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	int				size_a;
	int				size_b;
}	t_state;

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

/* Opertions */
void	ft_rot_top(t_stack **stack, int size, char c);
void	ft_rot_both_top(t_state **state);
void	ft_pb(t_state **state);
void	ft_pa(t_state **state);
void	ft_rot(t_stack **stack, int size, char c);
void	ft_rot_both(t_state **state);
void	ft_r_rot(t_stack **stack, int size, char c);
void	ft_r_rot_both(t_state **state);

/* Sorting process */
int		ft_sort(t_stack *stack);
void	ft_sort_a_to_b(t_state **state);
void	ft_sort_b_to_a(t_state **state);
void	ft_final_rot(t_state **state);

/* Stack utils */
t_stack	*ft_get_max(t_stack **stack);
t_stack	*ft_get_min(t_stack **stack);
void	ft_idx_stack(t_stack **stack);
t_stack	*ft_get_cheapest(t_stack **stack);
void	ft_node_to_top(t_stack **stack, t_stack *node, int size, char c);
void	ft_move_both_top(t_state **state, t_stack *a, t_stack *b);

/* Utils */
t_state	*ft_init_state(t_stack *stack_a);
int		ft_is_sorted(t_stack *stack);
void	ft_print_stack(t_stack **stack, int med, int cheapest, int cost);
void	ft_print_state(t_state **state);
int		ft_med_cost(t_stack *node, int size);
void	ft_set_cheapest(t_stack **stack);
void	ft_set_above_med(t_stack **stack, int size);

/* Error handling */
void	ft_puterror(void);

#endif
