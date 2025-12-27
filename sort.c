/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:04:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/27 01:19:45 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *stack_a) //remove these function
{
    while (stack_a)
    {
        printf("%d ", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("\n");
}

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
        four_five_numbers(stack_a, stack_b);
    }
}
void sort(t_stack **stack_a)
{
    t_stack *stack_b;
    int numbers_in_stack;

    stack_b = NULL;
    print_stack(*stack_a);
    numbers_in_stack = calc_number_in_stack(*stack_a);
    if (numbers_in_stack <= 5)
        sort_small_numbers(stack_a, &stack_b);
    print_stack(*stack_a);
}