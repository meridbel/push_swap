/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 18:08:23 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/31 18:12:28 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_of_next_chunk(t_stack *a, int limit)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->rank < limit)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

static int	find_the_max(t_stack *stack_b)
{
	int	index;
	int	i;
	int	max;

	index = 0;
	i = 0;
	max = stack_b->rank;
	while (stack_b)
	{
		if (stack_b->rank > max)
		{
			max = stack_b->rank;
			index = i;
		}
		stack_b = stack_b->next;
		i++;
	}
	return (index);
}

static void	push_stack_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	pushed;
	int	limit;
	int	index;
	int	size;

	size = calc_number_in_stack(*stack_a);
	if (size <= 100)
		chunk = 15;
	else
		chunk = 30;
	pushed = 0;
	while (*stack_a)
	{
		limit = chunk + pushed;
		if ((*stack_a)->rank < limit)
		{
			push_b(stack_a, stack_b);
			if ((*stack_b)->rank <= pushed)
				rotate_b(stack_b);
			pushed++;
		}
		else
		{
			index = index_of_next_chunk(*stack_a, limit);
			size = calc_number_in_stack(*stack_a);
			if (index <= size / 2)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
	}
}

static void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	size;

	while (*stack_b)
	{
		size = calc_number_in_stack(*stack_b);
		index = find_the_max(*stack_b);
		if (index <= size / 2)
		{
			while (index-- > 0)
				rotate_b(stack_b);
		}
		else
		{
			while (index++ < size)
				reverse_rotate_b(stack_b);
		}
		push_a(stack_a, stack_b);
	}
}

void	the_big_algo_2(t_stack **stack_a, t_stack **stack_b)
{
	push_stack_a_to_b(stack_a, stack_b);
	push_back_to_a(stack_a, stack_b);
}
