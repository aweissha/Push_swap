/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:15:22 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/19 17:21:58 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h";

int main (int argc, char **argv)
{
	char	**array;
	t_stack	*stack_a;
	
	if (argc == 2)
		array = ft_split(argv[1], ' ');
	else
		array = &argv[1];
	stack_a = ft_make_stack_a(array);
	
	

}