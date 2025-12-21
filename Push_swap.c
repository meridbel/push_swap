/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 23:11:28 by meridbel          #+#    #+#             */
/*   Updated: 2025/12/21 23:09:05 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
int duplicate_helper(char *av, char c)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (av[i] == c)
            return (0);
        i++;
    }
    return (1);
}
int check_duplicate(char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (!(duplicate_helper(av, av[i])))
            return (0);
        i++;
    }
    return (1);
}

int check_error(int ac, char *av)
{
    int i;

    i = 0;
    while (av[i])
    {
        if (ac == 1)
            return (0);
        else if (!(av[i] >= 0 && av[i] <= 9)
        {
            write(1, "Error", 5);
            return (0);
        }
        else if (!(check_duplicate(av[i])))
        {
            write(1, "Error", 5);
            return (0);
        }
    }
    return (1);
}

int main (int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        if (!(check_error(ac, av[i])))
            return (0);
        i++;
    }
    write(1, "no error", 8);
    return (0);
}
