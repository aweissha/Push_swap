/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:53:01 by aweissha          #+#    #+#             */
/*   Updated: 2023/12/01 14:58:55 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
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
t_stack	*ft_stnew(int number, int index);
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
void	ft_rotate_max_up(t_stack **stack_b);
int		ft_stsize(t_stack *stck);
void	ft_push_back(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stck);
void	ft_insert_algorithm(t_stack **stack_a, t_stack **stack_b);
void	ft_first_two(t_stack **stack_a, t_stack **stack_b);
int		ft_max_number(t_stack *stck);
int		ft_max_index(t_stack *stck);
t_stack	*ft_max_element(t_stack *stck);
int		ft_check_ascending(t_stack *stck);
int		all_top(t_stack *a, t_stack *b);
int		all_bot(t_stack **st_a, t_stack **st_b, t_stack *a, t_stack *b);
int		top_bot(t_stack **st_b, t_stack *a, t_stack *b);
int		bot_top(t_stack **st_a, t_stack *a, t_stack *b);
int		ins_steps(t_stack **st_a, t_stack **st_b, t_stack *a, t_stack *b);
void	m_all_top(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b);
void	m_all_bot(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b);
void	m_top_bot(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b);
void	m_bot_top(t_stack **st_a, t_stack **st_b, t_stack *c, t_stack *b);
void	rotate(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest);
t_stack	*ft_cheapest_element(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_target(t_stack **stack_b, t_stack *counter_a);
void	ft_sort_two(t_stack **stack_a);

#endif