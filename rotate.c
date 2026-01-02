/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 19:05:24 by meridbel          #+#    #+#             */
/*   Updated: 2026/01/01 20:12:58 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **header)
{
	t_stack	*first;
	t_stack	*last;

	if (!header || !*header || !(*header)->next)
		return ;
	first = *header;
	*header = first->next;
	last = *header;
	while (last->next)
	{
		last = last->next;
	}
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
	write(1, "rr\n", 3);
}
