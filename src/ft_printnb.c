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

int			ft_printnb(t_flags *p, char **f, va_list arg)
{
	int 	i;
	int 	a;
	char 	*nb;

	i = 0;
	if (ft_strchr("OoUuXxp", **f))
		nb = ft_get_unb(p, f, arg); //**f is on d for e.g.
	else
		nb = ft_get_snb(p, f, arg); //maybe to pass the address of nb into func!
	if (*nb == '0')
	{
		(*f)++;
		return(write(1, "0", 1));
	}
	(p->sharp && (**f == 'o' || **f == 'O')) ? (a = 1) : 0;
	(**f == 'p' || (p->sharp && (**f == 'x' || **f == 'X'))) ? (a = 2) : 0;
	if (p->zero)
	{
		(**f == 'p' || (p->sharp && **f == 'x')) ? (i = write(1, "0x", 2)) : 0;
		(p->sharp && **f == 'X') ? (i = write(1, "0X", 2)) : 0;
	}
	if (p->min) //|| (p->min && (p->plus || p->space)))//0 is ign. with -, ' ' is ign. with +
	{
		(p->sharp && (**f == 'o' || **f == 'O')) ? (i = write(1, "0", 1)) : 0;
		i += ft_min(p, nb, f, i);
	}
	else if (p->zero || p->plus || p->space)
		i += ft_zero_plus_space(p, nb, i);
	else
	{
		if (ft_strlen(nb) >= p->prc)
		{
			p->wd > ft_strlen(nb) ? i = ft_put(' ', p->wd - ft_strlen(nb) - a) : 0;
			(**f == 'p' || (p->sharp && **f == 'x')) ? (i += write(1, "0x", 2)) : 0;
			(p->sharp && **f == 'X') ? (i += write(1, "0X", 2)) : 0;
		}
		else if (ft_strlen(nb) < p->prc)
		{
			i += ft_put(' ', p->wd - p->prc - a);
			i += ft_put('0', p->prc - ft_strlen(nb));
		}
		(p->sharp && (**f == 'o' || **f == 'O')) ? (i += write(1, "0", 1)) : 0;
		i += write(1, nb, ft_strlen(nb));
	}
	(*f)++;
	ft_strdel(&nb);
	return (i);
}
