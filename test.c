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

    fd = 7;
    if (get_next_line(fd, &line) > 0)
    {
        ft_putendl("Should be failing");
    }
    else
        ft_putendl("Good???");
	
    if (get_next_line(f, &line) > 0)
    {
        ft_putendl("passed");
    }
    else
        ft_putendl("what???");
    return (0);
}

int     main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    *stdline;
    char    *temp;
	int		i;

	i = 0;
    if (ac != 2)
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
    else
    {
        fd = open(av[1], O_RDONLY);
		ft_putendl_i("Fild descriptor is :: ", fd);
        while (get_next_line(fd, &line) > 0)
        {
            temp = line;
            ft_putendl(line);
            free(temp);
            i++;
        }
        if (line)
            free(line);
        close(fd);
    }
    return (0);
}
