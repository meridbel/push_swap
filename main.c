/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:11:28 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/26 15:39:50 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **split, int x)
{
	x = x - 1;
	while (x >= 0)
	{
		free(split[x]);
		x--;
	}
	free (split);
	return (NULL);
}

static int start_function(int k, int ac, int *numbers, char **av, t_stack **stack_a)
{
     char **split;
     int i;

     while (k < ac)
     { 
         split = ft_split(av[k], ' ');
         if (!split || !split[0])
                 return (write(2, "Error\n", 6), 0);
        i = 0;
        while (split[i])
        {
            if (!check_error(split[i]) || !ft_atoi(split[i], numbers)
            || !is_duplicate(*stack_a, *numbers))
            {
                ft_free(split, i);
                return (write(2, "Error\n", 6), 0);
            }
            add_number(stack_a, *numbers);
            i++;
        }
        ft_free(split, i);
        k++;
    }
    return (1);
}

int main (int ac, char **av)
{
    int numbers;
    t_stack *stack_a;

    stack_a = NULL;
    numbers = 0;
    if (ac == 1 || !start_function(1, ac, &numbers, av, &stack_a))
            return (0);
    sort(&stack_a);
    return (0);
}
