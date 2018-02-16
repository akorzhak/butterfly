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

static int		ft_unicode_wide(unsigned int c, char **temp)
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
	int 			i;

	c = (unsigned int)va_arg(arg, wchar_t);
	if (c == 0)
		return (ft_printc(ptr, f, c));
	res = ft_strnew(4);
	t = res;
	(c < 2048) ? (ft_unicode_short(c, &t)) : (ft_unicode_wide(c, &t));
	(ptr->prc) ? (ptr->prc = ft_strlen(res)) : 0;
	i = ft_prints(ptr, f, res);
	ft_strdel(&res);
	return (i);
}

static void		ft_fillarr(t_flags *ptr, unsigned int *arr, char *res)
{
	unsigned int 	c;
	char			*t;

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
}

int				ft_unicode_s(t_flags *ptr, char **f, va_list arg)
{
	unsigned int	*arr;
	char			*res;
	int				i;

	if (ptr->dot && !ptr->prc)
		return (ft_prints(ptr, f, "\0"));
	arr = (unsigned int *)va_arg(arg, int *);
	if (arr == NULL)
		return (ft_prints(ptr, f, "(null)"));
	if (*arr == '\0' && (*f)++)
		return (0);
	res = ft_strnew(ft_intlen(arr) * 4);	
	ft_fillarr(ptr, arr, res);	
	i = ft_prints(ptr, f, res);
	ft_strdel(&res);
	return (i);
}
