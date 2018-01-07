/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:50:18 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:50:20 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*res;

	res = dest;
	while (*dest)
		dest++;
	while (*src && ((n--) > 0))
		*(dest++) = *(src++);
	*dest = '\0';
	return (res);
}
