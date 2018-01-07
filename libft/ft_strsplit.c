/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:45:08 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:45:12 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	let_count(char const *str, char c)
{
	size_t		len;

	len = 1;
	while (*str != c && *(str++))
		len++;
	return (len);
}

static size_t	word_count(char const *str, char c)
{
	size_t		nb;

	nb = 0;
	while (*str)
	{
		if (*str != c)
			nb++;
		while (*str != c && *str != '\0')
			str++;
		while (*str == c)
			str++;
	}
	return (nb);
}

static char		**filling(char const *s, char c, char **arr, size_t words)
{
	size_t		a;
	size_t		b;

	a = 0;
	while (a < words)
	{
		b = 0;
		while (*s == c)
			s++;
		if ((arr[a] = (char*)malloc(sizeof(char) * let_count(s, c))) == NULL)
			return (NULL);
		while (*s != c && *s)
			arr[a][b++] = *(s++);
		arr[a++][b] = '\0';
	}
	arr[a] = 0;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	if ((arr = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	return (filling(s, c, arr, words));
}
