/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:32:03 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:56:14 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strmapi(t_cstr s, char (*f)(t_uint, char))
{
	t_str	str;
	t_uint	i;

	if (s && f)
	{
		i = 0;
		str = ft_memalloc(ft_strlen((t_str)s) + 1);
		if (!str)
			return (0);
		ft_strcpy(str, s);
		while (str[i])
		{
			str[i] = (*f)(i, str[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
