/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 13:23:04 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/30 13:23:49 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int index_of_max(t_stack *b)
{
    int max;
    int index;
    int i;

    max = b->rank;
    index = 0;
    i = 0;
    while (b)
    {
        if (b->rank > max)
        {
            max = b->rank;
            index = i;
        }
        b = b->next;
        i++;
    }
    return (index);
}


void push_back_to_a(t_stack **a, t_stack **b)
{
    int index;
    int size;

    while (*b)
    {
        size = calc_number_in_stack(*b);
        index = index_of_max(*b);

        if (index <= size / 2)
            while (index-- > 0)
                rotate_b(b);
        else
            while (index++ < size)
                reverse_rotate_b(b);

        push_a(a, b);
    }
}


void big_algo(t_stack **a, t_stack **b)
{
    push_chunks_to_b(a, b);
    push_back_to_a(a, b);
}