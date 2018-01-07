/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:05:38 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/05 14:05:41 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*ncontent;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		if (!(ncontent = ft_memalloc(content_size)))
		{
			free(new);
			return (0);
		}
		ft_memcpy(ncontent, content, content_size);
		new->content = ncontent;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
