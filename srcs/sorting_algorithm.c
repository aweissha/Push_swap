/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:24:18 by aweissha          #+#    #+#             */
/*   Updated: 2023/11/28 19:48:15 by aweissha         ###   ########.fr       */
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

t_stack	*ft_max_element(t_stack *stck)
{
	int	max_number;
	t_stack	*max;
	
	max_number = stck->number;
	max = stck;
	while (stck != NULL)
	{
		if (stck->number > max_number)
		{
			max = stck;
			max_number = stck->number;		
		}
		stck = stck->next;
	}
	return (max);
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

// Pushes tho two upper elements of stack_a to stack_b. Checked!
void	ft_first_two(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_b) < 2 && ft_stsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
}

int	ft_steps_all_top(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	if ((counter_a->index) >= (target_b->index))
		return (counter_a->index);
	else
		return (target_b->index);
}

int	ft_steps_all_bot(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	if ((ft_stsize(*stack_a) - (counter_a->index)) >= (ft_stsize(*stack_b) - (target_b->index)))
		return (ft_stsize(*stack_a) - (counter_a->index));
	else
		return (ft_stsize(*stack_b) - (target_b->index));
}

int	ft_steps_top_bot(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	return ((counter_a->index) + (ft_stsize(*stack_b) - (target_b->index)));
}

int	ft_steps_bot_top(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	return ((target_b->index) + (ft_stsize(*stack_a) - (counter_a->index)));
}

int	ft_insertion_steps(t_stack **stack_a, t_stack **stack_b, t_stack *counter_a, t_stack *target_b)
{
	int	steps;
	int tmp;

	steps = ft_steps_all_top(stack_a, stack_b, counter_a, target_b);
	tmp = ft_steps_all_bot(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	tmp = ft_steps_top_bot(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	tmp = ft_steps_bot_top(stack_a, stack_b, counter_a, target_b);
	if (tmp < steps)
		steps = tmp;
	return (steps);
}

t_stack	*ft_find_target(t_stack **stack_b, t_stack *counter_a)
{
	t_stack	*counter_b;
	t_stack	*target;
	int	tmp;

	tmp = INT32_MIN;
	counter_b = *stack_b;
	while (counter_b != NULL)
	{
		if ((counter_b->number < counter_a->number) && (counter_b->number > tmp))
		{
			tmp = counter_b->number;
			target = counter_b;
		}
		counter_b = counter_b->next;
	}
	if (tmp == INT32_MIN)
		target = ft_max_element(*stack_b);
	return (target);
}


/* This function loops through stack_a and calculates for every element the costs of rotating it to the top of the stack_a +
rotating stack_b to bring the target to the top of stack_b + pushing the element from stack_a to stack_b. The possibility of rotating
stack_a and stack_b at the same time has to be considered * 
*/
t_stack	*ft_cheapest_element(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*counter_a;
	t_stack *target_b;
	t_stack	*cheapest;
	int	insertion_steps;
	int	min_steps;

	min_steps = INT32_MAX;
	counter_a = *stack_a;

	while (counter_a != NULL)
	{
		target_b = ft_find_target(stack_b, counter_a);
		insertion_steps = ft_insertion_steps(stack_a, stack_b, counter_a, target_b);
		if (insertion_steps < min_steps)
		{
			min_steps = insertion_steps;
			cheapest = counter_a;
		}
		counter_a = counter_a->next;
	}
	return (cheapest);		
}

void	ft_move_all_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0 && target_b->index != 0)
		ft_rr(stack_a, stack_b);
	while (cheapest_element->index != 0)
		ft_ra(stack_a);
	while (target_b->index != 0)
		ft_rb(stack_b);
}

void	ft_move_all_bot(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0 && target_b->index != 0)
		ft_rrr(stack_a, stack_b);
	while (cheapest_element->index != 0)
		ft_rra(stack_a);
	while (target_b->index != 0)
		ft_rrb(stack_b);
}

void	ft_move_top_bot(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0)
		ft_ra(stack_a);
	while (target_b->index != 0)
		ft_rrb(stack_b);
}

void	ft_move_bot_top(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element, t_stack *target_b)
{
	while (cheapest_element->index != 0)
		ft_rra(stack_a);
	while (target_b->index != 0)
		ft_rb(stack_b);
}

/* This function rotates stack_a until the cheapest element is at the top. Stack_b gets rotated until the target is at the top.
 If possible, the two stacks rotate at the same time using rr or rrr.
*/
void	ft_execute_rotations(t_stack **stack_a, t_stack **stack_b, t_stack *cheapest_element)
{
	t_stack	*target_b;
	int	a;
	int	b;
	int	c;
	int	d;
	
	target_b = ft_find_target(stack_b, cheapest_element);
	a = ft_steps_all_top(stack_a, stack_b, cheapest_element, target_b);
	b = ft_steps_all_bot(stack_a, stack_b, cheapest_element, target_b);
	c = ft_steps_top_bot(stack_a, stack_b, cheapest_element, target_b);
	d = ft_steps_bot_top(stack_a, stack_b, cheapest_element, target_b);
	
	if (a <= b && a <= c && a <= d)
		ft_move_all_top(stack_a, stack_b, cheapest_element, target_b);
	else if (b <= a && b <= c && b <= d)
		ft_move_all_bot(stack_a, stack_b, cheapest_element, target_b);
	else if (c <= a && c <= b && c <= d)
		ft_move_top_bot(stack_a, stack_b, cheapest_element, target_b);
	else
		ft_move_bot_top(stack_a, stack_b, cheapest_element, target_b);
}

void	ft_insert_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_stsize(*stack_a) > 3)
	{
		ft_execute_rotations(stack_a, stack_b, ft_cheapest_element(stack_a, stack_b));
		ft_pb(stack_a, stack_b);
	}
}

void	ft_rotate_max_up(t_stack **stack_b)
{
	int	median;
	t_stack	*max_element;

	max_element = ft_max_element(*stack_b);
	median = ft_stsize(*stack_b) / 2;
	if ((max_element->index) <= median)
		{
			while (max_element->index != 0)
				ft_rb(stack_b);
		}
	if ((max_element->index) > median)
		{
			while (max_element->index != 0)
				ft_rrb(stack_b);
		}
}

/*This function Pushes back all the descendingly sorted elements of stack_b to stack_a.
The three ascendingly sorted elements of stack_a have to be considered*/
void	ft_push_back(t_stack **stack_a, t_stack **stack_b)
{
	int	counter;
	
	ft_rotate_max_up(stack_b);
	// ft_print_stack(*stack_a);
	// ft_print_stack(*stack_b);

	counter = 0;
	if ((((*stack_b)->number) > ((*stack_a)->number)) && (((*stack_b)->number) < ((*stack_a)->next->number)))
	{
		ft_ra(stack_a);
		counter = 2;
	}
	else if ((((*stack_b)->number) < ((*stack_a)->number)))
		counter = 3;
	while (*stack_b != NULL)
	{
		if ((ft_stlast(*stack_a)->number) > ((*stack_b)->number) && counter < 3)
		{
			ft_rra(stack_a);
			counter++;
		}
		else
			ft_pa(stack_a, stack_b);
	}
	// ft_print_stack(*stack_a);
	// ft_print_stack(*stack_b);
	while (ft_check_ascending(*stack_a) != 0)
		ft_rra(stack_a);
}

void	ft_sorting_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	// Push the first two elements of stack_a to stack_b
	ft_first_two(stack_a, stack_b);

	/* calculate the costs for each element of stack_a to bring to the top and insert into the correct position of stack_b.
	Then executing the insertion for the cheapest element.**/
	ft_insert_algorithm(stack_a, stack_b);

	// /*Sort the remaining three elements of stack_a*/
	ft_sort_three(stack_a);
	
	// 	ft_rb(stack_b);
	// ft_print_stack(*stack_a);
	// ft_print_stack(*stack_b);

	// /*Push all the now descending sorted elements of stack_b back to stack_a. The remaining three elements of stack_a have to be considered.*/
	if (*stack_b != NULL)
		ft_push_back(stack_a, stack_b);
}
