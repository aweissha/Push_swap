/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:53:01 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/21 16:03:35 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //entfernen !
# include "libft.h"

typedef struct s_stack
{
	long			number;
	long			index;
	struct s_stack	*previous;
	struct s_stack	*next;
}	t_stack;

int		ft_error(void);
void	ft_free_array(char **array);
void	ft_free_stack(t_stack *stck);
t_stack	*ft_make_stack_a(char **array);
void	ft_stadd_back(t_stack **stck, t_stack *new);
t_stack	*ft_stlast(t_stack *stck);
t_stack	*ft_stnew(long number, long index);
int		ft_check_multiples(t_stack *stck);




#endif