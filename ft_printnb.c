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

#include "libftprintf.h"

static int 	ft_put(char c, int nb)
{
	int 	i;

	i = nb;
	while (nb--)
		ft_putchar(c);
	return (i);
}

static int 	ft_zero_plus_space(t_flags *p, char *nb)
{
	int 	i;
	char	*n;
	int 	len;

	i = 0;
	n = nb;
	(n[0] == '-') ? (n++) : 0;
	len = ft_strlen(n);
	if (p->width > (p->prc + p->plus))
	{
		if (p->prc >= len)
			i = ft_put(' ', p->width - p->prc - p->plus);
		else
			i = ft_put(' ', p->width - len - p->plus);
	}
	(p->plus && nb[0] != '-') ? (ft_putchar('+'), i++) : 0;
	(p->space && !p->plus && nb[0] != '-') ? (ft_putchar(' '), i++) : 0;
	(nb[0] == '-') ? (ft_putchar('-'), i++) : 0;
	(p->prc > len) ? (i += ft_put('0', p->prc - len)) : 0;
	i += write(1, n, len);
	return (i);
}

static int 	ft_min(t_flags *p, char *nb)
{
	int 	i;
	char	*n;
	int 	len;
	char	flag;

	i = 0; //for - or +
	n = nb;
	(p->plus) ? (flag = '+', i++) : 0;
	(p->space && !p->plus) ? (flag = ' ', i++) : 0;
	(nb[0] == '-') ? (ft_putchar('-'), n++) : (ft_putchar(flag));
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
		i += ft_put('0', p->prc - len) + write(1, n, len);
	return (i);
}

int			ft_printnb(t_flags *ptr, char **f, va_list arg)
{
	int 	i = 1;
	char 	*nb;
	char	*temp;

	if (ft_strchr("OoUuXxp", **f))
		nb = ft_get_unb(ptr, f, arg); //**f is on d for e.g.
	else
		nb = ft_get_snb(ptr, f, arg); //maybe to pass the address of nb into func!
	if (**f == 'p')
	{
		temp = nb;
		nb = ft_strjoin("0x7fff", nb);
		ft_strdel(&temp);
	}
	(*f)++;
	if (ptr->min) //|| (ptr->min && (ptr->plus || ptr->space)))//0 is ign. with -, ' ' is ign. with +
		i = ft_min(ptr, nb);
	else if (ptr->zero || ptr->plus || ptr->space)
		i = ft_zero_plus_space(ptr, nb);
	else
		i = write(1, nb, ft_strlen(nb));
	return (i);
}

