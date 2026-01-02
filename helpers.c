/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:01:05 by meridbel          #+#    #+#             */
/*   Updated: 2026/01/02 13:47:23 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

static char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	srclen;
	char	*alocate;

	i = 0;
	srclen = ft_strlen (s);
	alocate = malloc (srclen + 1);
	if (alocate == NULL)
		return (NULL);
	while (i < srclen)
	{
		alocate[i] = s[i];
		i++;
	}
	alocate[i] = '\0';
	return (alocate);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	slen;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	substring = malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	while (len > 0)
	{
		substring[i] = s[start];
		start++;
		i++;
		len--;
	}
	substring[i] = '\0';
	return (substring);
}

void	helper_of_a_to_b(t_stack **stack_b, t_stack **stack_a
		, int limit, int chunk)
{
	int	pushed;
	int	index;
	int	size;

	pushed = 0;
	pushed = calc_number_in_stack(*stack_b);
	limit = chunk + pushed;
	if ((*stack_a)->rank < limit)
	{
		push_b(stack_a, stack_b);
		if ((*stack_b)->rank <= pushed)
			rotate_b(stack_b);
		pushed++;
	}
	else
	{
		index = index_of_next_chunk(*stack_a, limit);
		size = calc_number_in_stack(*stack_a);
		if (index <= size / 2)
			rotate_a(stack_a);
		else
			reverse_rotate_a(stack_a);
	}
}

int	helper_of_start_function(char	**split, t_stack **stack_a,
		int *numbers, int i)
{
	while (split[i])
	{
		if (check_error(split[i]) || !ft_atoi(split[i], numbers)
			|| is_duplicate(*stack_a, *numbers))
		{
			free_stack(*stack_a);
			ftt_free(split);
			write(2, "Error\n", 6);
			return (0);
		}
		add_number(stack_a, *numbers);
		i++;
	}
	ftt_free(split);
	return (1);
}
