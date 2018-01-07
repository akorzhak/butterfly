/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:29:24 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/03 14:29:26 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *arr;
	char *res;

	res = NULL;
	if (s && f)
	{
		if (!(arr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (res);
		res = arr;
		while (*s)
			*(arr++) = f((char)*(s++));
		*arr = '\0';
	}
	return (res);
}
