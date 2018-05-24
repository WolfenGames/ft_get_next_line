/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:48:06 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 17:24:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strsub(t_cstr s1, t_uint start, size_t len)
{
	int		i;
	t_str	substr;
	
	if (!s1)
		return (NULL);
	substr = ft_memalloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (len--)
	{
		substr[i] = s1[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
