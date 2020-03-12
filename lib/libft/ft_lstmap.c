/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:21:18 by ooliinyk          #+#    #+#             */
/*   Updated: 2019/02/08 16:28:55 by ooliinyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*list;

	if (!lst || !f || !*f)
		return (NULL);
	newlst = f(lst);
	list = newlst;
	while (lst->next != NULL)
	{
		newlst->next = (*f)(lst->next);
		newlst = newlst->next;
		lst = lst->next;
	}
	newlst->next = NULL;
	return (list);
}
