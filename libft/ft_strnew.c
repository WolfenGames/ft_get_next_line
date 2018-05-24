/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:02:58 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:57:24 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str	ft_strnew(size_t size)
{
	t_str	str;

	if ((str = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
