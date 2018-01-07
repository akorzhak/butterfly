/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:40:25 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/05 18:40:29 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *ret;

	if (lst && f)
	{
		new = f(lst);
		ret = new;
		while (lst->next != NULL)
		{
			lst = lst->next;
			new->next = f(lst);
			new = new->next;
		}
		if (lst->next == NULL)
		{
			new->next = 0;
		}
		return (ret);
	}
	return (NULL);
}
