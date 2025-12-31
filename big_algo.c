/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 00:50:59 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/31 18:37:36 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*set_array(t_stack **stack_a, int numbers_in_stack)
{
	int		i;
	int		*array;
	t_stack	*temp;

	i = 0;
	array = malloc(sizeof(int) * numbers_in_stack);
	if (!array)
		return (NULL);
	temp = *stack_a;
	while (temp)
	{
		array[i] = temp->value;
		i++;
		temp = temp->next;
	}
	return (array);
}

static int	*sort_the_array(int *array, int numbers_in_stack)
{
	int	i;
	int	k;
	int	temp;

	k = 0;
	while (k < numbers_in_stack)
	{
		i = 0;
		while (i < numbers_in_stack - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		k++;
	}
	return (array);
}

void	set_rank(t_stack **stack_a, int nbr, int rank)
{
	t_stack	*header;

	header = *stack_a;
	while (header)
	{
		if (header->value == nbr)
			header->rank = rank;
		header = header->next;
	}
}

void	the_big_algo(t_stack **stack_a, t_stack **stack_b, int numbers_in_stack)
{
	int	*array;
	int	i;

	array = set_array(stack_a, numbers_in_stack);
	i = 0;
	if (!array)
		return ;
	array = sort_the_array(array, numbers_in_stack);
	while (i < numbers_in_stack)
	{
		set_rank(stack_a, array[i], i);
		i++;
	}
	the_big_algo_2(stack_a, stack_b);
}
