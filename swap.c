/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:47:18 by meridbel          #+#    #+#             */
/*   Updated: 2026/01/01 19:46:20 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **header)
{
	t_stack	*first;
	t_stack	*second;

	if (!header || !*header || !(*header)->next)
		return ;
	first = *header;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*header = second;
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
