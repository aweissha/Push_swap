/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:53:01 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/28 14:43:11 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //entfernen !
# include "libft.h"

int global_variable; // entfernen !

typedef struct s_stack
{
	int			number;
	int			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

long	ft_atoi_mod(const char *str);
int		ft_error(void);
void	ft_free_array(char **array);
void	ft_free_stack(t_stack *stck);
int		ft_make_stack_a(char **array, t_stack **stack_a);
void	ft_stadd_back(t_stack **stck, t_stack *new);
t_stack	*ft_stlast(t_stack *stck);
t_stack	*ft_stnew(long number, long index);
int		ft_check_multiples(char **array);
int		ft_syntax_error(char *str);
void	ft_set_index(t_stack *stck);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
int		ft_max_number(t_stack *stck);
int		ft_max_index(t_stack *stck);
int		ft_check_ascending(t_stack *stck);
void	ft_sort_three(t_stack **stck);
void	ft_first_two(t_stack **stack_a, t_stack **stack_b);
void	ft_sorting_algorithm(t_stack **stack_a, t_stack **stack_b);
int		ft_stsize(t_stack *stck);
void	ft_print_stack(t_stack *stck); // entfernen !
#endif