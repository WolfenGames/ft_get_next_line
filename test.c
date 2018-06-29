/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:23:51 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/28 10:05:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     badfiles(int f)
{
    int     fd;
    char    *line;
    char    *line_2;

    fd = 7;
    if (get_next_line(fd, &line) > 0)
    {
        ft_putendl("Should be failing");
    }
    else
        ft_putendl("Good???");
	
    if (get_next_line(f, &line_2) > 0)
    {
        ft_putendl("passed");
    }
    else
        ft_putendl("what???");

    if (get_next_line(f, (void *)0) > 0)
    {
        ft_putendl("What??");
    }
    else
        ft_putendl("Cool");

    if (get_next_line(-1000000, (void *)0) > 0)
    {
        ft_putendl("Waht???");
    }
    else
        ft_putendl("passed");

    return (0);
}

int     main(int ac, char **av)
{
    int     fd;
    int     fd2;
    int     fd3;
    char    *line;
    char    *line_1;
    char    *line_2;
    char    *stdline;
    char    *temp;
	int		i;

	i = 0;
    if (ac == 1)
    {
        while (get_next_line(0, &stdline))
        {
            temp = stdline;
            ft_putendl_c("Std Line Output :: ", stdline);
            if (ft_strequ(stdline, "rbf"))
            {
				fd = open("t", O_RDONLY);
                return (badfiles(fd));
            }
            if (ft_strequ(stdline, "Exit") || ft_strequ(stdline, "exit"))
            {
                free(stdline);
                return (0);
            }
            free(stdline);
        }
    }
    else if (ac == 3)
    {
        fd2 = open(av[1], O_RDONLY);
        fd3 = open(av[2], O_RDONLY);
        while (i < 100)
        {
            if (get_next_line(fd2, &line_1) > 0)
            {
                temp = line_1;
                ft_putendl_c("FD1 :: ", line_1);
                free (temp);
            }
            if (get_next_line(fd3, &line_2) > 0)
            {
                temp = line_2;
                ft_putendl_c("FD 2 :: ", line_2);
                free(temp);
            }
            i++;
        }
    }
    else if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
		ft_putendl_i("Fild descriptor is :: ", fd);
        while (get_next_line(fd, &line) > 0)
        {
            temp = line;
            ft_putendl_c("Line Data :: ", line);
            free(temp);
            i++;
        }
        if (line)
            free(line);
        close(fd);
    }
    return (0);
}
