/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:06:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/31 18:52:19 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	if (av[i] == '+' || av[i] == '-')
	{
		if (av[i + 1] == '\0')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	while (av[i])
	{
		if (av[i] < '0' || av[i] > '9')
		{
			write(1, "Error\n", 6);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(const char *nptr, int *num)
{
	int		i;
	long	m;
	int		sign;

	i = 0;
	m = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		m = m * 10 + nptr[i++] - '0';
	m = m * sign;
	if ((sign == 1 && m > 2147483647) || (sign == -1 && m < -2147483648))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	*num = (int)m;
	return (1);
}

int	is_duplicate(t_stack *head, int value)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	add_number(t_stack **head, int t)
{
	t_stack	*tmp;

	if (*head == NULL)
	{
		*head = malloc(sizeof(t_stack));
		(*head)->value = t;
		(*head)->next = NULL;
		return ;
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = malloc(sizeof(t_stack));
	tmp->next->value = t;
	tmp->next->next = NULL;
}
