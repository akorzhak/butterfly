/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:24:55 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/05 10:24:58 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			size_of_arr(int n)
{
	int				len;
	unsigned int	val;

	len = 1;
	(n < 0) ? (val = (unsigned int)n * -1) : 0;
	(n >= 0) ? (val = (unsigned int)n) : 0;
	while ((val / 10) > 0)
	{
		val /= 10;
		len++;
	}
	(n < 0) ? (len++) : 0;
	return (len);
}

char				*ft_itoa(int n)
{
	char			*arr;
	int				len;
	unsigned int	val;

	len = size_of_arr(n);
	(n < 0) ? (val = (unsigned int)n * -1) : 0;
	(n >= 0) ? (val = (unsigned int)n) : 0;
	if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	arr[len--] = '\0';
	while ((val / 10) > 0)
	{
		arr[len--] = (char)((val % 10) + '0');
		val /= 10;
	}
	(val < 10) ? (arr[len--] = (char)(val + '0')) : 0;
	(!len) ? (arr[len] = '-') : 0;
	return (arr);
}
