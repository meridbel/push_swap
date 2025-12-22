/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 00:06:12 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/22 18:36:11 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_valid_string(char a)
{
    if (!((a >= '0' && a <= '9') || ((a == '-') || (a == '+'))))
        return (0);

    return (1);
}

int check_error(char *av)
{
    int i;

    i = 0;
    if (!av)
        return (0);
    while (av[i])
    {
        if (!check_valid_string(av[i]))
        {
            write(2, "Error", 5);
            return (0);
        }
        i++;
    }
    return (1);
}

int check_valid_number(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if ((str[i] == '-') || (str[i] == '+'))
            if ((str[i + 1] == '-') || (str[i + 1] == '+'))
                return (write(2, "error", 5), 0);       
    }
    return (1);
}
// int main ()
// {
//     char *str = "--124";
//     check_valid_number(str);
// }