/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcillard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 15:33:23 by tcillard          #+#    #+#             */
/*   Updated: 2018/11/17 15:50:51 by tcillard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;
	t_list *save;
	t_list *ret;

	save = f(lst);
	res = ft_lstnew(save->content, save->content_size);
	ret = res;
	lst = lst->next;
	while (lst)
	{
		save = f(lst);
		res->next = ft_lstnew(save->content, save->content_size);
		res = res->next;
		lst = lst->next;
	}
	return (ret);
}
