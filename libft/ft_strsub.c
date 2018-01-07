/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:34:39 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/04 14:34:41 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *arr;
	char *ret;

	if (s)
	{
		if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		ret = arr;
		while (len--)
			*(arr++) = s[start++];
		*arr = '\0';
		return (ret);
	}
	return (0);
}
