/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:04:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/31 19:02:53 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int greater_than(t_stack *header)
{
	t_stack *first;
	t_stack *second;

	first = header;
	second = first->next;
	if (first->value > second->value)
		return (0);
	return (1);
}

static void sort_small_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int numbers_in_stack;
	
	numbers_in_stack = calc_number_in_stack(*stack_a);
	if (numbers_in_stack == 2)
		if (!greater_than(*stack_a))
			swap_a(stack_a);
	if (numbers_in_stack == 3)
		sort_three_numbers(stack_a);
	if (numbers_in_stack == 4 || numbers_in_stack == 5)
	{
		four_numbers(stack_a, stack_b);
	}
}
void sort(t_stack **stack_a)
{
	t_stack *stack_b;
	int numbers_in_stack;

	stack_b = NULL;
	numbers_in_stack = calc_number_in_stack(*stack_a);
	if (numbers_in_stack <= 5)
		sort_small_numbers(stack_a, &stack_b);
	else
		the_big_algo(stack_a, &stack_b, numbers_in_stack);
}