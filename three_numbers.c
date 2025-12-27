/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:52:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/26 18:41:05 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_number_in_stack(t_stack *stack_a)
{
    int number;
    
    number = 0;
    while(stack_a)
    {
        stack_a = stack_a->next;
        number++;
    }
    return (number);
}

static void finish_sort_three_numbers(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;            

    first = *stack_a;
    second = first->next;
    third = second ->next;
    if ((first->value < second->value) && (second->value > third->value))
    {
        if (first->value < third->value)
            {
                swap_a(stack_a);
                rotate_a(stack_a);
            }
        else
            {
                swap_a(stack_a);
                rotate_a(stack_a);
                swap_a(stack_a);
            }
    }
}

 void  sort_three_numbers(t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;            

    first = *stack_a;
    second = first->next;
    third = second ->next;
    if ((first->value > second->value) && (first->value > third->value))
    {
        rotate_a(stack_a);
        if (!greater_than(*stack_a))
            swap_a(stack_a);
    }
    else if ((first->value > second->value) && (first->value < third->value))
        swap_a(stack_a);
    finish_sort_three_numbers(stack_a);
}
