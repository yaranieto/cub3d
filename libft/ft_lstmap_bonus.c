/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynieto-s <ynieto-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:04:51 by ynieto-s          #+#    #+#             */
/*   Updated: 2025/04/29 13:07:24 by ynieto-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_cont_ck(void *(*f)(void *), void (*d) (void *), void *cont);

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*last;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	last = NULL;
	while (lst)
	{
		new_node = ft_cont_ck(f, del, lst->content);
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		if (new_list == NULL)
			new_list = new_node;
		if (last != NULL)
			last->next = new_node;
		last = new_node;
		lst = lst->next;
	}
	return (new_list);
}

static t_list	*ft_cont_ck(void *(*f)(void *), void (*d) (void *), void *cont)
{
	t_list	*new_node;
	t_list	*new_content;

	new_content = f(cont);
	if (new_content == NULL)
	{
		d(new_content);
		return (NULL);
	}
	new_node = ft_lstnew(new_content);
	return (new_node);
}
