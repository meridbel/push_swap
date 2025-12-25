/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:11:28 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/25 23:12:17 by meridbel         ###   ########.fr       */
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

void print_stack(t_stack *stack_a) //remove these function
{
    while (stack_a)
    {
        printf("%d ", stack_a->value);
        stack_a = stack_a->next;
    }
    printf("\n");
}

int main (int ac, char **av)
{
    int numbers;
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    numbers = 0;
    if (ac == 1 || !start_function(1, ac, &numbers, av, &stack_a))
            return (0);
    return (0);
}
