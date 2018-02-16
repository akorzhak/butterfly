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

#include "../includes/libftprintf.h"

static int			size_of_arr(uintmax_t val, int base)
{
	int				len;

	len = 1;
	while (val >= base)
	{
		val /= base;
		len++;
	}
	return (len);
}

static char			*itoa_base(intmax_t value, int base)
{
	char			*arr;
	int				len;
	uintmax_t		val;

	len = 0;
	(value < 0) ? (len++) : 0;
	(value < 0) ? (val = (uintmax_t)value * -1) : 0;
	(value >= 0) ? (val = (uintmax_t)value) : 0;
	len += size_of_arr(val, base);
	if (!(arr = ft_strnew(len)))
		return (NULL);
	arr[len--] = '\0';
	(val == 0) ? (arr[len] = '0') : 0;
	while (val > 0)
	{
		((val % base) < 10) ? (arr[len--] = (char)(val % base + '0')) :
		(arr[len--] = (char)(val % base - 10 + 'A'));
		val /= base;
	}
	(!len && value != 0) ? (arr[len] = '-') : 0;
	return (arr);
}

char			*ft_get_snb(t_flags *ptr, char **f, va_list arg)
{
	intmax_t 	nb;
	char 		*n; 

	if (**f == 'D' || ptr->l)
		nb = va_arg(arg, long);
	else if (ptr->h)
		nb = (short)(va_arg(arg, int));
	else if (ptr->hh)
		nb = (char)(va_arg(arg, int));
	else if (ptr->ll)
		nb = va_arg(arg, long long);
	else if (ptr->z)
		nb = va_arg(arg, size_t);
	else if (ptr->j)
		nb = va_arg(arg, intmax_t);
	else
		(**f == 'd' || **f == 'i') ? (nb = va_arg(arg, int)) : 0;
	(!nb) ? (n = ft_strnew(1)) : 0;
	(!nb) ? (*n = '0') : 0;
	(nb) ? (n = itoa_base(nb, 10)) : 0;
	return (n);
}
