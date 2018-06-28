/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:23:51 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/21 15:58:25 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     badfiles()
{
    int     fd;
    char    *line;

    fd = -1;
    if (get_next_line(fd, &line) > 0)
    {
        ft_putendl("Should be failing");
    }
    else
        ft_putendl("Good???");
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
                close(0);
                return (badfiles());
            }
            if (ft_strequ(stdline, "Exit") || ft_strequ(stdline, "exit"))
            {
                free(stdline);
                close(0);
                return (0);
            }
            free(stdline);
        }
    }
    else
    {
        fd = open(av[1], O_RDONLY);
        while (get_next_line(fd, &line))
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
