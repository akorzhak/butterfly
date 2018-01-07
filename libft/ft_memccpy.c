/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 16:10:27 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/28 16:10:29 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *d, const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i++ < n)
	{
		*(unsigned char *)d = *(unsigned char *)(s++);
		if (*(unsigned char *)(d++) == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
