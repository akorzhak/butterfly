/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:51:25 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:51:27 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			size_of_arr(int value, int base)
{
	int				len;
	unsigned int	val;

	len = 1;
	(value < 0) ? (val = (unsigned int)value * -1) : 0;
	(value >= 0) ? (val = (unsigned int)value) : 0;
	while (val >= (unsigned int)base)
	{
		val /= (unsigned int)base;
		len++;
	}
	return (len);
}

char				*ft_itoa_base(int value, int base)
{
	char			*arr;
	int				len;
	unsigned int	val;

	len = size_of_arr(value, base);
	(value < 0) ? (val = (unsigned int)value * -1) : 0;
	(value >= 0) ? (val = (unsigned int)value) : 0;
	if (value < 0)
		(base == 10) ? (len++) : 0;
	if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	arr[len--] = '\0';
	(value == 0) ? (arr[len] = '0') : 0;
	while (val > 0)
	{
		((val % base) < 10) ? (arr[len--] = (char)(val % base + '0')) :
		(arr[len--] = (char)(val % base - 10 + 'A'));
		val /= base;
	}
	(!len && value != 0) ? (arr[len] = '-') : 0;
	return (arr);
}
