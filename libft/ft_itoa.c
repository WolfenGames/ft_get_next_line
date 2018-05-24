/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 19:29:59 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 15:03:35 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_charcount(long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int		ft_ifneg(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

t_str			ft_itoa(int n)
{
	long	l;
	size_t	cnt;
	t_str	str;
	int		neg;

	l = n;
	neg = ft_ifneg(l);
	cnt = ft_charcount(l);
	str = ft_strnew(cnt + neg);
	if (str == NULL)
		return (NULL);
	if (neg)
	{
		l = -l;
		str[0] = '-';
	}
	while (cnt > 0)
	{
		str[cnt + neg - 1] = (l % 10) + '0';
		cnt--;
		l /= 10;
	}
	return (str);
}
