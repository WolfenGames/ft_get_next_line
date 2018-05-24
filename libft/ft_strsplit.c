/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:19:27 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 10:30:21 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lststr	ft_strsplit(t_cstr s, char c)
{
	t_lststr	ret;
	int			xc;
	int			yc;
	int			start;

	if (!s || !c ||
			!(ret = ft_memalloc(sizeof(t_str) * ft_wordcount(s, c) + 1)))
		return (NULL);
	xc = 0;
	yc = 0;
	while (s[xc])
	{
		if (s[xc] == c)
			xc++;
		else
		{
			start = xc;
			while (s[xc] && s[xc] != c)
				xc++;
			ret[yc++] = ft_strsub(s, start, xc - start);
		}
	}
	ret[yc] = 0;
	return (ret);
}
