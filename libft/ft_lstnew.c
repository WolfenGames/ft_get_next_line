/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:56:08 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 15:46:40 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(t_cvoid content, size_t content_size)
{
	t_list	*ret;
	size_t	i;

	i = 0;
	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		ret->content = malloc(content_size);
		if (ret->content)
		{
			i = 0;
			while (++i < content_size + 1)
			{
				((unsigned char *)ret->content)[i - 1] = 
				 ((unsigned char *)content)[i - 1];
			}
		}
		ret->content_size = content_size;
	}
	else
	{
		ret->content = NULL;
		ret->content_size = 0;
	}
	ret->next = NULL;
	return (ret);
}
