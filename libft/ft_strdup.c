/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:47:34 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:54:05 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strdup(t_cstr s1)
{
	t_str	ret;
	size_t	i;
	size_t	f;

	f = ft_strlen((t_str)s1);
	i = 0;
	if ((ret = (t_str)malloc(sizeof(char) * (f + 1))) == NULL)
		return (NULL);
	while (i < f)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
