/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:49:14 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/31 19:26:45 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	if (!stack_one || !*stack_one)
		return ;
	tmp = *stack_one;
	*stack_one = tmp->next;
	tmp->next = *stack_two;
	*stack_two = tmp;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
