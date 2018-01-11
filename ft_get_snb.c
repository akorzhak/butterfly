/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_snb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:50 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/11 16:45:52 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			size_of_arr(intmax_t value, int base)
{
	int				len;

	len = 1;
	(value < 0) ? (value = -value) : 0;
	while (value >= base)
	{
		value /= base;
		len++;
	}
	return (len);
}

static char			*ft_s_itoa_base(intmax_t value, int base)
{
	char			*arr;
	int				len;
	intmax_t		val;

	val = value;
	len = size_of_arr(value, base);
	(value < 0) ? (len++) : 0;
	(value < 0) ? (value = -value) : 0;

	if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	arr[len--] = '\0';
	(value == 0) ? (arr[len] = '0') : 0;
	while (value > 0)
	{
		((value % base) < 10) ? (arr[len--] = (char)(value % base + '0')) :
		(arr[len--] = (char)(value % base - 10 + 'A'));
		value /= base;
	}
	(!len && val != 0) ? (arr[len] = '-') : 0;
	return (arr);
}

char	*ft_get_snb(t_flags *ptr, char **f, va_list arg) //dDi
{
	intmax_t nb; 

	if (ptr->h)
		nb = (short)(va_arg(arg, int));
	else if (ptr->hh)
		nb = (char)(va_arg(arg, int));
	else if (ptr->l)
		nb = va_arg(arg, long);
	else if (ptr->ll)
		nb = va_arg(arg, long long);
	else if (ptr->z)
		nb = va_arg(arg, size_t);
	else if (ptr->j)
		nb = va_arg(arg, intmax_t);
	else
	{
		(**f == 'd' || **f == 'i') ? (nb = va_arg(arg, int)) : 0;
		(**f == 'D') ? (nb = va_arg(arg, long)) : 0;
	}
	return (ft_s_itoa_base(nb, 10));
}
