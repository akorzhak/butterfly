/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:13 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:16 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *nextl;
	t_list *list;

	list = *alst;
	if (alst && del)
	{
		while (list)
		{
			*alst = list;
			nextl = list->next;
			del(list->content, list->content_size);
			ft_memdel((void **)alst);
			list = nextl;
		}
	}
}
