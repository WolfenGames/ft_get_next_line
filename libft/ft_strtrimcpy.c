/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 12:23:22 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 17:12:30 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strtrimcpy(t_str ret, t_cstr s, int start, int end)
{
	int		c;

	c = 0;
	if (!ret || !s)
		return (NULL);
	while (start <= end)
	{
		ret[c] = s[start];
		start++;
		c++;
	}
	ret[c] = '\0';
	return (ret);
}
