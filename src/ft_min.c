/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 14:47:14 by akorzhak          #+#    #+#             */
/*   Updated: 2018/02/17 14:47:16 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*ft_handlecases(t_flags *p, char *nb, t_cnt *c)
{
	char *n;

	n = nb;
	if (p->plus && nb[0] != '-' && (c->i += write(1, "+", 1)))
		c->a++;
	if (p->space && !p->plus && (c->i += write(1, " ", 1)))
		c->a++;
	if (nb[0] == '-' && (c->i += write(1, "-", 1)))
	{
		c->a++;
		n++;
	}
	return (n);
}

static void	ft_handlecase(t_flags *p, char *n, char **f, t_cnt *c)
{
	int len;

	len = c->p;
	if (!p->prc || p->prc <= len)
	{
		if (**f == 's' || **f == 'S')
		{
			if (p->prc)
				c->i += write(1, n, p->prc) + ft_put(' ', p->wd - p->prc);
			else
				c->i += write(1, n, len) + ft_put(' ', p->wd - len);
		}
		else
		{
			c->i += write(1, n, len);
			if (p->wd > (len + c->a))
				c->i += ft_put(' ', p->wd - len - c->a);
		}
	}
	else if (p->prc && p->wd > p->prc)
	{
		if (**f != 's')
			c->i += ft_put('0', p->prc - len) + write(1, n, len);
		c->i += ft_put(' ', p->wd - c->i);
	}
}

int			ft_min(t_flags *p, char *nb, char **f, int a)
{
	t_cnt	*c;
	char	*n;
	size_t	len;
	int		i;

	c = (t_cnt *)ft_memalloc(sizeof(t_cnt));
	c->a = a;
	n = ft_handlecases(p, nb, c);
	len = ft_strlen(n);
	c->p = len;
	if (p->wd && p->wd > len && p->wd > p->prc)
		ft_handlecase(p, n, f, c);
	else if (!p->wd || p->wd <= p->prc)
	{
		if (p->prc > len)
			c->i += ft_put('0', p->prc - len) + write(1, n, len);
		(p->prc <= len || !p->prc) ? c->i += write(1, n, len) : 0;
	}
	else
		c->i += write(1, n, len);
	i = c->i;
	ft_memdel((void **)&c);
	return (i);
}
