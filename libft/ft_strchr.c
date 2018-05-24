/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 15:05:14 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:52:37 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strchr(t_cstr str, int c)
{
	size_t	i;
	t_str	s1;

	i = 0;
	s1 = (t_str)str;
	while (s1[i] && s1[i] != (char)c)
		i++;
	if (s1[i] == (char)c)
		return ((t_str)&s1[i]);
	else
		return (NULL);
}
