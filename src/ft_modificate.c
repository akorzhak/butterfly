/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modificate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:54:14 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:54:17 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int 	ft_put(char c, int nb)
{
	int 	i;

	i = nb;
	while (nb--)
		ft_putchar(c);
	return (i);
}

int 	ft_zero_plus_space(t_flags *p, char *nb, int a)
{
	int 	i;
	char	*n;
	int 	len;

	i = 0;
	n = nb;
	(n[0] == '-') ? (n++) : 0;
	len = ft_strlen(n);
	if (p->wd && !p->prc)
	{
		(p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
		i += ft_put('0', p->wd - len - p->plus - a);
	}
	else if (p->wd > (p->prc + p->plus))
	{
		if (p->prc >= len)
			i += ft_put(' ', p->wd - p->prc - p->plus);
		else
			i = ft_put(' ', p->wd - len - p->plus);
	}
	(p->space && !p->plus && nb[0] != '-') ? (ft_putchar(' '), i++) : 0;
	(nb[0] == '-') ? (ft_putchar('-'), i++) : 0;
	(p->prc && p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
	(p->prc >= len) ? (i += ft_put('0', p->prc - len)) : 0;
	i += write(1, n, len);
	return (i);
}

int 	ft_min(t_flags *p, char *nb, char **f, int a)
{
	int 	i;
	char	*n;
	int 	len;
	char	flag;

	i = 0; //for - or +
	n = nb;
	(p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
	(p->space && !p->plus) ? (ft_putchar(' '), i++) : 0;
	(nb[0] == '-') ? (ft_putchar('-'), n++) : 0;
	len = ft_strlen(n);
	if (p->wd && p->wd > len && p->wd > p->prc)
	{
		if (!p->prc || p->prc <= len)
		{
			if (**f == 's')
				i += write(1, n, p->prc) + ft_put(' ', p->wd - p->prc);
			else
				i += write(1, n, len) + ft_put(' ', p->wd - len - i - a);
		}
		else if (p->prc && p->wd > p->prc)
		{
			(**f != 's') ? i += ft_put('0', p->prc - len) + write(1, n, len) : 0;
			i += ft_put(' ', p->wd - i);
		}
	}
	else if (!p->wd || p->wd <= p->prc)
	{
		(p->prc > len) ? i += ft_put('0', p->prc - len) + write(1, n, len) : 0;
		(p->prc <= len || !p->prc) ? i += write(1, n, len) : 0;
	}
	return (i);
}
