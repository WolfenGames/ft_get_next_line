/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 07:14:50 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 09:20:15 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_c(char const *dest, char const *str)
{
	char	*temp;
	char	*join;

	join = NULL;
	if (dest && str)
	{
		temp = join;
		join = ft_strjoin(dest, str);
		ft_putendl(join);
		free(join);
	}
	else if (!str)
		ft_putendl(ft_strjoin(dest, "No string passed"));
}
