/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:50:48 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/30 18:48:30 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push_stack_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int numbers_pushed;
    int limit;
    int size;
    int chunk;

    size = calc_number_in_stack(*stack_a);
    if (size <= 150)
        chunk = 15;
    else chunk = 70;
    numbers_pushed = 0;
    limit = chunk;
    while (*stack_a)
    {
        if ((*stack_a)->rank < limit)
        {
            push_b(stack_a, stack_b);
            numbers_pushed++;
            if ((*stack_b)->rank < limit - chunk / 2)
                rotate_b(stack_b);
            if (numbers_pushed == limit)
                limit += chunk;
        }
        else
            rotate_a(stack_a);
    }
}

static int find_the_max(t_stack *stack_b)
{
    int index;
    int i;
    int max;

    max = stack_b->rank;
    i = 0;
    while(stack_b)
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



static void push_back_to_a(t_stack **stack_a,t_stack **stack_b)
{
    int index;
    int size;

    while (*stack_b)
    {
        size = calc_number_in_stack(*stack_b);
        index = find_the_max(*stack_b);
        if (index <= size / 2)
        {
            while (index > 0)
            {
                rotate_b(stack_b);
                index--;
            }
        }
        else
        {
            while (index < size)
            {
                reverse_rotate_b(stack_b);
                index++;
            }
        }
        push_a(stack_a, stack_b);
    }
}
void the_big_algo_2(t_stack **stack_a, t_stack **stack_b)
{
    push_stack_a_to_b(stack_a, stack_b);
    push_back_to_a(stack_a, stack_b);
}
