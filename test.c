/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:23:51 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/21 12:23:52 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    *temp;

    if (ac != 2)
        return (-1);
    fd = open(av[1], O_RDONLY);
    while (get_next_line(fd, &line))
    {
        temp = line;
        ft_putendl(line);
        free(temp);
    }
    if (line)
        free(line);
    close(fd);
    return (0);
}
