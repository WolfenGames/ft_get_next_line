/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:35:05 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/04 07:47:53 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <stdio.h>

int		ft_fdopen(char *file)
{
	int		fd;
	int		fd2;
	int		fd3;
	char	**data;
	char	**tst;
	char	*tmp;
	int		i;
	int		size;
	int		count;

	size = 0;
	count = 0;
	i = 0;
	data = ft_memalloc(sizeof(char *) * 1024);
	tst = ft_memalloc(sizeof(char *) * 1024);
	fd = open(file, O_RDONLY);
	fd2 = open("test.txt", O_RDONLY);
	fd3 = open("get_next_line.c", O_RDONLY);
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, data))
	{
		tst[i] = ft_strnew(ft_strlen(*data));
		tst[i] = ft_strdup(*data);
		i++;
	}
	while (get_next_line(fd2, data))
	{
		ft_putendl("Reading...");
	}
	while (get_next_line(fd3, data))
	{
		ft_putendl("Reading");
	}
	i = 0;
	while (*tst)
	{
		tmp = *tst;
		ft_putendl(*tst);
		if (!ft_strequ(tmp, *++tst))
			count++;
		i++;
	}
	ft_putendl(ft_itoa(count));
	ft_putendl(ft_itoa(i));
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
