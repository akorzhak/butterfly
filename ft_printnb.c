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

int		ft_printnb(t_flags *ptr, char **f, va_list arg)
{
	char *nb;

	if (ft_strchr("OoUuXxp", **f))
		nb = ft_get_unb(ptr, f, arg); //**f is on d for e.g.
	else
		nb = ft_get_snb(ptr, f, arg);
	(*f)++;
	return (ft_strlen(nb));
}

