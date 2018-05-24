/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:09:39 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/24 07:48:36 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(t_void , size_t))
{
	t_list	*n_lst;
	t_list	*temp;

	n_lst = *alst;
	while (n_lst)
	{
		if (del)
			(*del)(n_lst->content, n_lst->content_size);
		temp = n_lst->next;
		free(n_lst);
		n_lst = temp;
	}
	*alst = NULL;
}
