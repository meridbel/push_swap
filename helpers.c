/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:01:05 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/24 23:07:04 by meridbel         ###   ########.fr       */
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
