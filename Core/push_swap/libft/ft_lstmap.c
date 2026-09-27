/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 15:38:20 by pedved            #+#    #+#             */
/*   Updated: 2026/08/28 17:37:22 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstmap_error(t_list **new_list, void *content,
		void (*del)(void *))
{
	if (del != NULL)
		del(content);
	ft_lstclear(new_list, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_list;
	void	*updated_content;
	t_list	*new_node;

	if (lst == NULL || f == NULL)
		return (NULL);
	curr = lst;
	new_list = NULL;
	while (curr != NULL)
	{
		updated_content = f(curr->content);
		new_node = ft_lstnew(updated_content);
		if (new_node == NULL)
		{
			ft_lstmap_error(&new_list, updated_content, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		curr = curr->next;
	}
	return (new_list);
}
