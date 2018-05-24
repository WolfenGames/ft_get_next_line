/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:27:24 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 17:56:11 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strtrim(t_cstr s)
{
	t_str	str;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	str = ft_memalloc(ft_strlen((t_str)s));
	start = ft_clearspace(s, 0);
	end = ft_strlen((t_str)s);
	end = ft_clearspace(s, end);
	if (start > end)
		return (str = "\0");
	if (!(str = ft_memalloc((end - start) + 2)))
		return (NULL);
	return (ft_strtrimcpy(str, s, start, end));
}
