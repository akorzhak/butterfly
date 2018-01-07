/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:39:18 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/28 16:39:20 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ret;
	unsigned char *ds;
	unsigned char *sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	ret = (unsigned char *)dst;
	while (len--)
		if (ds > sr)
			ds[len] = sr[len];
		else
			*(ds++) = *(sr++);
	return (ret);
}
