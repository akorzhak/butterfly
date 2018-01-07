/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 17:56:57 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/04 17:57:00 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_fill(char *str, size_t b, size_t e)
{
	char	*arr;
	char	*ret;

	if ((arr = (char*)malloc(sizeof(char) * (e - b + 1))) == NULL)
		return (NULL);
	ret = arr;
	while (b < e)
		*(arr++) = str[b++];
	*arr = '\0';
	return (ret);
}

static char		*ft_trim(char const *str)
{
	char	*s;
	size_t	i;
	size_t	b;
	size_t	e;

	i = 0;
	e = 0;
	s = (char *)str;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	(s[i]) ? (b = i) : 0;
	(!s[i]) ? (b = 0) : 0;
	while (s[i])
	{
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
			i++;
		e = i;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
	}
	return (ft_fill(s, b, e));
}

char			*ft_strtrim(char const *s)
{
	if (s)
		return (ft_trim(s));
	return (0);
}
