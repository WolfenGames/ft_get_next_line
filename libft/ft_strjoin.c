/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:53:00 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 10:19:12 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strjoin(t_cstr s1, t_cstr s2)
{
	t_str	str;
	int		len;
	int		i;
	t_str	c1;
	t_str	c2;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	len = ft_strlen((t_str)s1) + ft_strlen((t_str)s2);
	str = ft_memalloc(len + 1);
	c1 = (t_str)s1;
	c2 = (t_str)s2;
	if (!str)
		return (NULL);
	while (*c1)
		str[++i] = *c1++;
	while (*c2)
		str[++i] = *c2++;
	str[++i] = '\0';
	return (str);
}
