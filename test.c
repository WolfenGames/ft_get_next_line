/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:35:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 16:32:13 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		ft_fdopen(char *file)
{
	int		fd;
	char	**data;
	char	**tst;
	int		i;

	i = 0;
	data = ft_memalloc(sizeof(char *) * 1024);
	tst = ft_memalloc(sizeof(char *) * 1024);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, data))
	{
			tst[i++] = ft_strdup(*data);
	}
	while (*tst)
		ft_putendl(*tst++);
	ft_memdel((void **)tst);
	close(fd);
	return (1);
}

int		main(int ac, char **argv)
{
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (ft_strlen(argv[i]) > 0 && !ft_strequ(argv[i], ""))
			{
				if (!ft_fdopen(argv[i]))
				{
					ft_putendl(ft_strjoin("Failed Opening :: ", argv[i]));
				}
				else
					ft_putendl(ft_strjoin("Working with :: ", argv[i]));
			}
			i++;
		}
	}
	return (0);
}
