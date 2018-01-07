/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:12:44 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/31 18:12:46 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t ret;

	if (dst && src)
	{
		ret = ft_strlen(src);
		if (size == 0)
			return (ret);
		while (*dst && size-- > 1 && *src)
			*(dst++) = *(src++);
		*dst = '\0';
		return (ret);
	}
	return (0);
}
