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

int     main(int ac, char **av)
{
    int     fd;
    char    *line;
    char    *temp;
	int		i;

	i = 0;
    if (ac != 2)
        return (-1);
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
    return (0);
}
