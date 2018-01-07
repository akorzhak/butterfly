/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:49:24 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:49:27 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *hay, char *ndl, size_t n)
{
	char	*res;
	int		i;
	int		j;
	size_t	len;

	if (!*ndl)
		return (hay);
	while (*hay && n && (res = hay))
	{
		i = 0;
		j = 0;
		len = n;
		while ((hay[i++] == ndl[j++]) && len)
		{
			if (!(ndl[j]))
				return (res);
			len--;
		}
		hay++;
		n--;
	}
	return (NULL);
}
