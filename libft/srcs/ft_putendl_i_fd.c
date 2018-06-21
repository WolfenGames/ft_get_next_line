/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_i_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:06:07 by jwolf             #+#    #+#             */
/*   Updated: 2018/06/11 09:20:03 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_i_fd(char const *str, int a, int fd)
{
	ft_putendl_fd(ft_strjoin(str, ft_itoa(a)), fd);
}
