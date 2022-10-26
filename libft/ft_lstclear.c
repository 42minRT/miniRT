/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:46:26 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 14:37:15 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			next = tmp->next;
			ft_lstdelone(tmp, del);
			tmp = next;
		}
		*lst = NULL;
	}
}
