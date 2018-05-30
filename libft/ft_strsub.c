/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 00:48:06 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 09:30:38 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s1, unsigned int start, size_t len)
{
	int		i;
	char	*substr;

	if (!s1)
		return (NULL);
	if (!(substr = ft_memalloc(len + 1)))
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
