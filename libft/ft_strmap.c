/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:14:53 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 10:03:45 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strmap(t_cstr s, char (*f)(char))
{
	t_str	str;
	int		i;
	int		j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((t_str)s);
		str = ft_memalloc(j + 1);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
