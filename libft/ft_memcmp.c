/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:33:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:47:16 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(t_cvoid str1, t_cvoid str2, size_t n)
{
	unsigned const char	*s1;
	unsigned const char	*s2;
	
	s1 = (unsigned const char *)str1;
	s2 = (unsigned const char *)str2;
	while (n-- != 0)
		if (*s1++ != *s2++)
			return (*--s1 - *--s2);
	return (0);
}
