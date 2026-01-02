/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:11:28 by meridbel          #+#    #+#             */
/*   Updated: 2026/01/02 14:08:58 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ftt_free(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (NULL);
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
	return (NULL);
}

static int	check_sorted(t_stack *stack_a)
{
	while (stack_a && stack_a -> next != NULL)
	{
		if (stack_a->value > (stack_a)->next->value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack *stack_a)
{
	t_stack	*tmp;

	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a);
		stack_a = tmp;
	}
}

static int	start_function(int ac, int *numbers, char **av, t_stack **stack_a)
{
	char	**split;
	int		i;
	int		k;

	k = 1;
	i = 0;
	while (k < ac)
	{
		split = ft_split(av[k], ' ');
		if (!split || !split[0])
		{
			ftt_free(split);
			return (write(2, "Error\n", 6), 0);
		}
		i = 0;
		if (!helper_of_start_function(split, stack_a, numbers, i))
			return (0);
		k++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		numbers;
	t_stack	*stack_a;
	int		k;

	stack_a = NULL;
	numbers = 0;
	k = 1;
	if (ac < 2 || !start_function(ac, &numbers, av, &stack_a))
		return (0);
	if (check_sorted(stack_a) == 0)
	{
		free_stack(stack_a);
		return (0);
	}
	sort(&stack_a);
	free_stack(stack_a);
	return (0);
}
