/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:57:19 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/31 18:57:22 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = 0;
	while (*s)
	{
		if (*s != (char)c)
			s++;
		else
			ret = ((char *)s++);
	}
	if (ret)
		return (ret);
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
