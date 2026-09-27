/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedved <pedved@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/27 11:07:15 by pedved            #+#    #+#             */
/*   Updated: 2026/08/27 11:29:57 by pedved           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;
	t_list			*curr;

	if (lst == NULL)
		return (0);
	count = 0;
	curr = lst;
	while (curr != NULL)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}
