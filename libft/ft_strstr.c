/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:40:24 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:40:27 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *hay, char *ndl)
{
	char	*res;
	char	*t;
	char	*temp;
	size_t	n;

	temp = hay;
	n = 1;
	if (!*ndl)
		return (hay);
	while (*hay)
	{
		t = ndl;
		(*hay == *ndl) ? (res = hay) : 0;
		while ((*hay == *t) && *(hay++))
			t++;
		if (!(*t))
			return (res);
		hay = temp + n++;
		while ((*hay != *ndl) && *hay)
			hay++;
	}
	return (NULL);
}
