/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwolf <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 15:13:25 by jwolf             #+#    #+#             */
/*   Updated: 2018/05/23 13:37:53 by jwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_new;
	t_list	*temp;
	t_list	*lst_new;

	if (!lst)
		return (NULL);
	lst_new = lst;
	temp = (*f)(lst_new);
	if ((ret_new = ft_lstnew(temp->content, temp->content_size)) == NULL)
		return (NULL);
	ret = ret_new;
	lst_new = lst_new->next;
	while (lst_new)
	{
		temp = (*f)(lst_new);
		ret_new->next = ft_lstnew(temp->content, temp->content_size);
		if (ret_new->next == NULL)
			return (NULL);
		ret_new = ret_new->next;
		lst_new = lst_new->next;
	}
	return (ret);
}
