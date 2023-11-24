/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:18 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/24 20:02:17 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_number(t_stack *stck)
{
	int	max_number;
	
	max_number = stck->number;
	while (stck != NULL)
	{
		if (stck->number > max_number)
			max_number = stck->number;
		stck = stck->next;
	}
	return (max_number);
}

int	ft_max_index(t_stack *stck)
{
	int	max_number;
	int	max_index;
	
	max_number = stck->number;
	max_index = 0;
	while (stck != NULL)
	{
		if (stck->number > max_number)
		{
			max_index = stck->index;
			max_number = stck->number;		
		}
		stck = stck->next;
	}
	return (max_index);
}


int	ft_check_ascending(t_stack *stck)
{
	int max_number;

	max_number = stck->number;
	stck = stck->next;
	while (stck != NULL)
	{
		if (stck->number < max_number)
			return (1);
		else
			max_number = stck->number;			
		stck = stck->next;
	}
	return (0);
}

void	ft_sort_three(t_stack **stck)
{
	int	max_index;
	
	max_index = ft_max_index(*stck);
	if (max_index == 0)
		ft_ra(stck);
	else if (max_index == 1)
		ft_rra(stck);
	if (ft_check_ascending(*stck) == 1)
		ft_sa(stck);
}

void	ft_first_two(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_b) < 2 && ft_stsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}

int	ft_insertion_steps(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	int median_a;
	int median_b;

	median_a = ft_stsize(*stack_a) / 2;
	median_b = ft_stsize(*stack_b) / 2;
}

t_stack	*ft_find_target(t_stack **stack_b, t_stack *counter_a)
{
	
}


/* This function loops through stack_a and calculates for every element the costs of rotating it to the top of the stack_a +
rotating stack_b to bring the target to the top of stack_b + pushing the element from stack_a to stack_b. The possibility of rotating
stack_a and stack_b at the same time has to be considered * 
*/
int	ft_cheapest_index(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*counter_a;
	t_stack *target_b;
	int	insertion_steps;
	int	min_steps;
	int	min_index;

	min_steps = INT32_MAX;
	counter_a = *stack_a;

	while (counter_a != NULL)
	{
		target_b = ft_find_target(stack_b, counter_a);
		insertion_steps = ft_insertion_steps(stack_a, stack_b, counter_a, target_b);
		if (insertion_steps < min_steps)
		{
			min_steps = insertion_steps;
			min_index = counter_a->index;
		}
		counter_a = counter_a->next;
	}
	return (min_index);		
}

/* This function rotates stack_a until the cheapest element is at the top. Stack_b gets rotated until the target is at the top.
 If possible, the two stacks rotate at the same time using rr or rrr.
*/
void	ft_execute_rotations(t_stack **stack_a, t_stack **stack_b, int cheapest_index)
{
	int median_a;
	int median_b;

	median_a = ft_stsize(*stack_a) / 2;
	median_b = ft_stsize(*stack_b) / 2;			
}

void	ft_insert_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_a) > 3)
	{
		ft_execute_rotations(stack_a, stack_b,ft_cheapest_index(stack_a, stack_b));
		ft_pb(stack_a, stack_b);
	}
	
}

/*This function Pushes back all the descendingly sorted elements of stack_b to stack_a.
The three ascendingly sorted elements of stack_a have to be considered*/
void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	
}

void	ft_sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	// Push the first two elements of stack_a to stack_b
	ft_first_two(stack_a, stack_b);

	/* calculate the costs for each element of stack_a to bring to the top and insert into the correct position of stack_b.
	Then executing the insertion for the cheapest element.**/
	ft_insert_algorithm(stack_a, stack_b);

	/*Sort the remaining three elements of stack_a*/
	ft_sort_three(stack_a);

	/*Push all the now descending sorted elements of stack_b back to stack_a. The remaining three elements of stack_a have to be considered.*/
	ft_push_back(stack_a, stack_b);
}
