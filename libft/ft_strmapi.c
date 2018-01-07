/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:35:10 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/03 15:35:14 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;
	char	*res;

	i = 0;
	res = NULL;
	if (s)
	{
		if ((arr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
			return (res);
		res = arr;
		while (*s)
			*(arr++) = f(i++, (char)*(s++));
		*arr = '\0';
	}
	return (res);
}
