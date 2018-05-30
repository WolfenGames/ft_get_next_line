/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:11:54 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/28 08:46:07 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*n_lst;

	if (!lst || !f)
		return ;
	n_lst = ft_memalloc(sizeof(n_lst));
	if (!n_lst)
		return ;
	n_lst = lst;
	while (n_lst)
	{
		(*f)(n_lst);
		n_lst = n_lst->next;
	}
}
