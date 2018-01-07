/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:46:56 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/04 14:46:58 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	char	*ret;
	size_t	len;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		if (!(arr = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		ret = arr;
		while (len-- && *s1)
			*(arr++) = *(s1++);
		while (len-- && *s2)
			*(arr++) = *(s2++);
		*arr = '\0';
		return (ret);
	}
	return (0);
}
