/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_five_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 20:00:09 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/27 02:10:06 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_min(t_stack *stack)
{
    int min;

    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

static void min_in_top(t_stack **stack_a)
{
    int min;
    t_stack *header;

    header = *stack_a;
    min = find_min(*stack_a);
    while (header)
    {
        if (header->value != min)
            rotate_a(stack_a);
        header = header->next;
    }
}

void    four_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
    int numbers_in_stack;
    numbers_in_stack = calc_number_in_stack(*stack_a);
    if (numbers_in_stack == 4)
    {
        min_in_top(stack_a);
        push_b(stack_a, stack_b);
        sort_three_numbers(stack_a);
        push_a(stack_a, stack_b);
    }
}