/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 22:04:48 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 22:04:51 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		let_count(char *str, int i)
{
	int		len;

	len = 1;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i++])
		len++;
	return (len);
}

static char		**fill(char *str, char **arr)
{
	int		i;
	int		a;
	int		b;

	i = 0;
	a = 0;
	b = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		arr[a] = (char*)malloc(sizeof(char) * let_count(str, i));
		while (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i])
			arr[a][b++] = str[i++];
		arr[a++][b] = '\0';
		b = 0;
	}
	arr[a] = (char*)malloc(sizeof(char));
	arr[a][b] = '\0';
	return (arr);
}

static int		word_count(char *str)
{
	int		i;
	int		nb;

	i = 0;
	nb = 1;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			nb++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
			i++;
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
	}
	return (nb);
}

char			**ft_split_white(char *str)
{
	char	**arr;

	if (str)
	{
		arr = (char**)malloc(sizeof(char*) * (word_count(str)));
		return (fill(str, arr));
	}
	return (0);
}
