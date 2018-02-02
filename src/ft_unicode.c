/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:51:01 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:51:04 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_unicode_c(unsigned int c)
{
	unsigned int m1 = 49280;
	unsigned int m2 = 14712960;
	unsigned int m3 = 4034953344;
	unsigned char u;
	int i;

	i = 0;
	if (c < 2048)
	{
		u = (m1 >> 8) | ((c >> 6) << 27) >> 27;
		i += write(1, &u, 1);
		u = ((m1 << 24) >> 24) | (c << 26) >> 26;
		i += write(1, &u, 1);
	}
	else if (c < 65536)
	{
		u = (m2 >> 16) | ((c >> 12) << 28) >> 28;
		i += write(1, &u, 1);
		u = ((m2 << 16) >> 24) | ((c >> 6) << 26) >> 26;
		i += write(1, &u, 1);
		u = ((m2 << 24) >> 24) | (c << 26) >> 26;
		i += write(1, &u, 1);
	}
	else
	{
		u = (m3 >> 24) | ((c >> 18) << 29) >> 29;
		i += write(1, &u, 1);
		u = ((m3 << 8) >> 24) | ((c >> 12) << 26) >> 26;
		i += write(1, &u, 1);
		u = ((m3 << 16) >> 24) | ((c >> 6) << 26) >> 26;
		i += write(1, &u, 1);
		u = ((m3 << 24) >> 24) | (c << 26) >> 26; 
		i += write(1, &u, 1);
	}
	return (i);
}

int				ft_unicode_s(t_flags *ptr, char **f, va_list arg)
{
	unsigned int	*arr;
	char			*res;
	int				i = 0;
	int				a;

	if (**f == 'C')
	{
		(*f)++;
		return (ft_unicode_c((unsigned int)va_arg(arg, wchar_t)));
	}
	a = 0;
	arr = (unsigned int *)va_arg(arg, int *);
	if (arr == NULL)
	{
		i = write(1, "(null)", 6);
		return (i);
	}
//	res = (unsigned char *)malloc(sizeof(char) * ft_strlen((char *)(arr)));
	while (*arr)
	{
		(*arr < 128) ? (i += write(1, arr, 1)) : 0;
		(*arr >= 128) ? (i += ft_unicode_c(*arr)) : 0;
		arr++;
	}
//	printf("%s\n", "aaaa");	
//	i = write(1, res, ft_strlen((char *)res));
	(*f)++;
	return (i);
}
