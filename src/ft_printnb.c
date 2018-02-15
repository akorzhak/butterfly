/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:54:14 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:54:17 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void 	ft_printnb_3(t_flags *p, char **f, char **nb, t_cnt *c)
{
	char 	*n;
	size_t len;

	n = *nb;
	(n[0] == '-') ? (n++) : 0;
	len = ft_strlen(n);
	if (len >= p->prc)
	{	
		p->wd > len ? c->i += ft_put(' ', p->wd - len - (*nb[0] == '-') - c->a) : 0;
		if (((**f == 'p') || (p->sharp && **f == 'x' && **nb != '0')) && c->a == 2)
			c->i += write(1, "0x", 2);
		(p->sharp && **f == 'X' && **nb != '0' && c->a) ? (c->i += write(1, "0X", 2)) : 0;
		(*nb[0] == '-') ? (c->i += write(1, "-", 1)) : 0;
	}
	else if (len < p->prc)
	{
		if (p->wd > p->prc)
			c->i += ft_put(' ', p->wd - p->prc - (*nb[0] == '-') - c->a);
		if (**f == 'p' && c->a == 2)
			c->i += write(1, "0x", 2);
		(*nb[0] == '-') ? (c->i += write(1, "-", 1)) : 0;
		c->i += ft_put('0', p->prc - len - c->p);
	}
	if (p->sharp && (**f == 'o' || **f == 'O') && **nb != '0' && c->a)
		c->i += write(1, "0", 1);
	c->i += write(1, n, len);
}

int 	ft_printnb_2(t_flags *p, char **f, char **nb, t_cnt *c)
{
	if (p->min) //|| (p->min && (p->plus || p->space)))//0 is ign. with -, ' ' is ign. with +
		c->i += ft_min(p, *nb, f, c->i);
	else if (p->zero || p->plus || p->space)
		ft_zero_plus_space(p, *nb, c);//	c->i += ft_zero_plus_space(p, *nb, c->i);
	else
		ft_printnb_3(p, f, nb, c);
	(*f)++;
	ft_strdel(nb);
	return (c->i);
}

int			ft_printnb(t_flags *p, char **f, va_list arg)
{
	t_cnt 	*c;
	char 	*nb;
	int 	i;

	i = 0;
	c = (t_cnt *)ft_memalloc(sizeof(t_cnt));
	if (ft_strchr("OoUuXxp", **f))
		nb = ft_get_unb(p, f, arg); //**f is on d for e.g.
	else
		nb = ft_get_snb(p, f, arg); //maybe to pass the address of nb into func!
	if (p->dot && !p->prc && *nb == '0')
	{
		if (**f == 'p')
		{
			(p->min) ? (i += write(1, "0x", 2)) : 0;
			(p->wd) ? (i += ft_put(' ', p->wd - 2)) : 0;
			(!p->min) ? (i += write(1, "0x", 2)) : 0;
		}
		else if ((**f == 'o' || **f == 'O') && p->sharp)
		{
			(p->min) ? (i += write(1, "0", 1)) : 0;
			(p->wd) ? (i += ft_put(' ', p->wd - 1)) : 0;
			(!p->min) ? (i += write(1, "0", 1)) : 0;
		}
		else
			(p->wd) ? (i = ft_put(' ', p->wd)) : 0;
		(*f)++;
		return (i);
	}
	(p->prc < ft_strlen(nb) && p->dot) ? (p->zero = 0) : 0;
	if (**f == 'p' || (ft_strchr("oOxX", **f) && p->sharp && *nb != '0'))
	{
		if (p->zero || p->min || p->wd <= ft_strlen(nb) || p->prc >= p->wd - 2)
		{
			if (**f == 'X' && (c->p = 2))
				c->i = write(1, "0X", 2);
			else if (**f == 'x' || **f == 'p')
			{
				c->i = write(1, "0x", 2);
				if ((**f == 'x' && p->prc < ft_strlen(nb)) || (**f == 'p' && p->zero))
					c->p = 2;
			}
			else
			{
				c->i = write(1, "0", 1);
				c->p = 1;
			}
		}
		else 
			(ft_strchr("oO", **f)) ? (c->a = 1) : (c->a = 2);
	}
	i = ft_printnb_2(p, f, &nb, c);
	ft_memdel((void **)&c);	
	return (i);
}
