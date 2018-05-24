/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:24:13 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:57:34 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strnstr(t_cstr hay, t_cstr needle, size_t n)
{
	size_t		i;
	size_t		j;

	if (!*needle)
		return ((t_str)hay);
	i = 0;
	while (hay[i] != '\0' && i < n)
	{
		j = 0;
		while (hay[i + j] && i + j < n && needle[i] && hay[i + j] == needle[j])
		j++;
		if (needle[j] == '\0')
			return ((t_str)(hay + i));
		i++;
	}
	return (NULL);
}
