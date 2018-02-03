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

static int	ft_unicode_wide(unsigned int c, char **temp)
{
	unsigned int mask2 = 14712960;
	unsigned int mask3 = 4034953344;

	if (c < 65536)
	{
		**temp = (mask2 >> 16) | ((c >> 12) << 28) >> 28;
		(*temp)++;
		**temp = ((mask2 << 16) >> 24) | ((c >> 6) << 26) >> 26;
		(*temp)++;
		**temp = ((mask2 << 24) >> 24) | (c << 26) >> 26;
		return (3);
	}
	else
	{
		**temp = (mask3 >> 24) | ((c >> 18) << 29) >> 29;
		(*temp)++;
		**temp = ((mask3 << 8) >> 24) | ((c >> 12) << 26) >> 26;
		(*temp)++;
		**temp = ((mask3 << 16) >> 24) | ((c >> 6) << 26) >> 26;
		(*temp)++;
		**temp = ((mask3 << 24) >> 24) | (c << 26) >> 26;
		return (4);
	}
}

static int		ft_unicode_short(unsigned int c, char **temp)
{
	unsigned int mask1 = 49280;

	if (c < 128)
	{
		**temp = c;
		return (1);
	}
	else
	{
		**temp = (mask1 >> 8) | ((c >> 6) << 27) >> 27;
		(*temp)++;
		**temp = ((mask1 << 24) >> 24) | (c << 26) >> 26;
		return (2);
	}	
}

int				ft_unicode_c(t_flags *ptr, char **f, va_list arg)
{
	unsigned int 	c;
	char			*res;
	char			*t;

	c = (unsigned int)va_arg(arg, wchar_t);
	res = ft_strnew(4);
	t = res;
	(c < 2048) ? (ft_unicode_short(c, &t)) : (ft_unicode_wide(c, &t));
	(ptr->prc) ? (ptr->prc = ft_strlen(res)) : 0;
	return (ft_prints(ptr, f, res)); //delete r!!!!!
}

int				ft_unicode_s(t_flags *ptr, char **f, va_list arg)
{
	unsigned int 	c;
	unsigned int	*arr;
	char			*res;
	char			*t;

	arr = (unsigned int *)va_arg(arg, int *);
	if (arr == NULL)
		return (ft_prints(ptr, f, "(null)"));
	res = ft_strnew(ft_intlen(arr) * 4);
	t = res;
	while (*arr)
	{
		(*arr < 2048) ? (c = ft_unicode_short(*arr, &t)) : 0;
		(*arr >= 2048) ? (c = ft_unicode_wide(*arr, &t)) : 0;
		arr++;
		if (ptr->prc && ft_strlen(res) > ptr->prc)
		{
			while (c--)
				*t-- = '\0';
			break;
		}
		t++;
	}
	return (ft_prints(ptr, f, res));
}
