/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:08:04 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 15:03:18 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_setreturn(int num, size_t b, t_bool neg)
{
	if (b > 10 && neg)
		return (0);
	if (b > 10)
		return (-1);
	if (neg)
		return (-num);
	return (num);
}

int				ft_atoi(t_cstr str)
{
	size_t	i;
	int		num;
	t_bool	neg;
	size_t	b;

	b = 0;
	i = 0;
	num = 0;
	neg = FALSE;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\n' || str[i] == '\f' || str[i] == '0')
		i++;
	if (str[i] == '-')
		neg = TRUE;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		b++;
		num *= 10;
		num += (str[i] - 48);
		i++;
	}
	return (ft_setreturn(num, b, neg));
}
