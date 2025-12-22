/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:11:28 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/22 18:55:01 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int ac, char **av)
{
    int k;
    int i;
    char **split;

    k = 1;
    i = 0;
    if (ac == 1)
            return (0);
    while (k < ac)
    {
        split = ft_split(av[k], ' ');
        if (!split)
            return (0);
        i = 0;
        while (split[i])
        {
            if (check_error(split[i]) == 0)
                return (0);
            else if (!check_valid_number(split[i]))
                return(0);
            i++;
        }
        k++;
    }
    return (0);
}
