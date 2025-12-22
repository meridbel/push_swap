/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:05:09 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/22 17:46:53 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	if (str[i] != '\0')
		count = 1;
	while (str[i])
	{
		if (str[i] && str[i] == c)
		{
			if ((str[i + 1] != '\0') && (str[i + 1] != c))
				count++;
		}
		i++;
	}
	return (count);
}

static int	word_len(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

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

static char	**complet_split(char const *s, char **split, char c)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len = word_len(s + i, c);
			split[x] = ft_substr(s, i, len);
			if (split[x] == NULL)
				return (ft_free(split, x));
			i += len;
			x++;
		}
	}
	split[x] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((sizeof(char *)) * (count_word(s, c) + 1));
	if (split == NULL)
		return (NULL);
	return (complet_split(s, split, c));
}

int main ()
{
	char *str = "   54   625 623  ";
	char **split;
	split = ft_split(str, ' ');
	int i = 0;
	while (i < 3)
	{
		printf("%s\n", split[i]);
		i++;
	}
}