/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:06:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/22 16:02:13 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid_string(char a)
{
    if (!(a >= '0' && a <= '9'))
        return (0);

    return (1);
}

int check_error(int ac, char *av)
{
    int i;

    i = 0;
    if (!av)
        return (0);
    while (av[i])
    {
        if (ac == 1)
            return (0);
        else if (!check_valid_string(av[i]))
        {
            write(2, "Error", 5);
            return (0);
        }
        i++;
    }
    return (1);
}