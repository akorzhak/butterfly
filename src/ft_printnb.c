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

int			ft_printnb(t_flags *ptr, char **f, va_list arg)
{
	int 	i;
	char 	*nb;

	if (ft_strchr("OoUuXxp", **f))
		nb = ft_get_unb(ptr, f, arg); //**f is on d for e.g.
	else
		nb = ft_get_snb(ptr, f, arg); //maybe to pass the address of nb into func!
	(*f)++;
	if (ptr->min) //|| (ptr->min && (ptr->plus || ptr->space)))//0 is ign. with -, ' ' is ign. with +
		i = ft_min(ptr, nb);
	else if (ptr->zero || ptr->plus || ptr->space)
		i = ft_zero_plus_space(ptr, nb);
	else
	{
		if (ft_strlen(nb) >= ptr->prc)
			i = ft_put(' ', ptr->width - ft_strlen(nb));
		else if (ft_strlen(nb) < ptr->prc)
		{
			i = ft_put(' ', ptr->width - ptr->prc);
			i += ft_put('0', ptr->prc - ft_strlen(nb));
		}
		i += write(1, nb, ft_strlen(nb));
	}
	ft_strdel(&nb);
	return (i);
}
