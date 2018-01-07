/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:02:30 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/31 14:02:34 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t ret;

	if (ft_strlen(dst) > size)
		return (ft_strlen((char*)src) + size);
	ret = ft_strlen(dst) + ft_strlen(src);
	while (*dst && size--)
		dst++;
	while (size-- > 1 && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (ret);
}
