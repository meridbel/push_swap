/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 00:52:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/25 01:19:48 by meridbel         ###   ########.fr       */
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