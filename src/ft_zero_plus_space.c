/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modificate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:54:14 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:54:17 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void		ft_printsign(t_flags *p, char *nb, t_cnt *c)
{
	if (p->plus && nb[0] != '-')
	{
		c->i += write(1, "+", 1);
		c->p++;
	}
	if (nb[0] == '-')
	{
		c->i += write(1, "-", 1);
		c->a++;
	}
}

static void		ft_handlecase1(t_flags *p, char *nb, t_cnt *c, int len)
{
	if (p->zero)
		ft_printsign(p, nb, c);
	if (p->zero && p->wd > len + p->plus)
		(p->plus) ? c->i += ft_put('0', p->wd - len - p->plus) : 0;
	if (p->space && (c->i += write(1, " ", 1)))
	{
		p->space = 0;
		c->p++;
	}
	if (p->wd > len + c->a + c->p)
	{
		if (p->zero)
			(!p->plus) ? c->i += ft_put('0', p->wd - len - c->a - c->p) : 0;
		else
			c->i += ft_put(' ', p->wd - len - c->a - p->plus);
	}
	if (!p->zero)
		ft_printsign(p, nb, c);
	(p->sharp && !p->zero) ? (c->i += ft_put('0', 1)) : 0;
}

static void		ft_handlecase2(t_flags *p, char *nb, t_cnt *c, int len)
{
	if (p->prc > len)
	{
		c->i += ft_put(' ', p->wd - p->prc -
			(nb[0] == '-' || p->plus || p->space));
	}
	else
	{
		c->i += ft_put(' ', p->wd -
			(nb[0] == '-' || p->plus || p->space) - len);
		(p->sharp && *nb != '0') ? (c->i += write(1, "0", 1)) : 0;
	}
}

int				ft_zero_plus_space(t_flags *p, char *nb, t_cnt *c)
{
	char	*n;
	int		len;

	n = nb;
	(n[0] == '-') ? (n++) : 0;
	len = ft_strlen(n);
	if (p->wd && !p->prc)
		ft_handlecase1(p, nb, c, len);
	else if (p->wd > p->prc + (p->plus || (nb[0] == '-' || p->space)))
		ft_handlecase2(p, nb, c, len);
	if (p->space && !p->plus && nb[0] != '-')
		c->i += write(1, " ", 1);
	if (nb[0] == '-' && !c->a)
		c->i += write(1, "-", 1);
	if (p->plus && !c->p && nb[0] != '-')
		c->i += write(1, "+", 1);
	if (p->prc >= len)
		c->i += ft_put('0', p->prc - len);
	c->i += write(1, n, len);
	return (c->i);
}
