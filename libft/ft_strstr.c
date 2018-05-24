/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:24:13 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:59:00 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strstr(t_cstr hay, t_cstr needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen((t_str)needle) == 0)
		return ((t_str)hay);
	while (hay[i])
	{
		while (needle[j])
		{
			if (hay[i + j] == needle[j])
				j++;
			else
			{
				j = 0;
				break ;
			}
		}
		if (needle[j] == '\0')
			return ((t_str)hay + i);
		i++;
	}
	return (NULL);
}
