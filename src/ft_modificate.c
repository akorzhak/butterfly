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

int 	ft_zero_plus_space(t_flags *p, char *nb)
{
	int 	i;
	char	*n;
	int 	len;

	i = 0;
	n = nb;
	(n[0] == '-') ? (n++) : 0;
	len = ft_strlen(n);
	if (p->width && !p->prc)
	{
		(p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
		i += ft_put('0', p->width - len - p->plus);
	}
	else if (p->width > (p->prc + p->plus))
	{
		if (p->prc >= len)
			i += ft_put(' ', p->width - p->prc - p->plus);
		else
			i = ft_put(' ', p->width - len - p->plus);
	}
	(p->space && !p->plus && nb[0] != '-') ? (ft_putchar(' '), i++) : 0;
	(nb[0] == '-') ? (ft_putchar('-'), i++) : 0;
	(p->prc && p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
	(p->prc >= len) ? (i += ft_put('0', p->prc - len)) : 0;
	i += write(1, n, len);
	return (i);
}

int 	ft_min(t_flags *p, char *nb)
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
	if (p->width && p->width > len && p->width > p->prc)
	{
		if (!p->prc || p->prc <= len)
			i += write(1, n, len) + ft_put(' ', p->width - len - i);
		else if (p->prc && p->width > p->prc)
		{
			i += ft_put('0', p->prc - len) + write(1, n, len);
			i += ft_put(' ', p->width - i);
		}
	}
	else if (!p->width || p->width <= p->prc)
	{
		(p->prc > len) ? i += ft_put('0', p->prc - len) + write(1, n, len) : 0;
		(p->prc <= len || !p->prc) ? i += write(1, n, len) : 0;
	}
	return (i);
}
