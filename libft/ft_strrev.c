/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:34:15 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:34:17 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *src)
{
	size_t	len;
	size_t	a;
	char	temp;

	len = ft_strlen(src);
	a = 0;
	while (a < --len)
	{
		temp = src[a];
		src[a++] = src[len];
		src[len] = temp;
	}
	return (src);
}
