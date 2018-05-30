/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 02:32:03 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 12:41:14 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	i = 0;
	if (s)
	{
		i = 0;
		str = ft_strdup(s);
		if (str)
		{
			while (str[i])
			{
				str[i] = (*f)(i, str[i]);
				i++;
			}
		}
		else
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
