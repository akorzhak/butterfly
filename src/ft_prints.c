/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:51:01 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:51:04 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"


int			ft_prints(t_flags *ptr, char **f, va_list arg)
{
	int i;
	char *s;

	s = va_arg(arg, char *);
	if (ptr->min)
		i = ft_min(ptr, s);
	else if (ptr->zero || ptr->plus || ptr->space)
		i = ft_zero_plus_space(ptr, s);
	else if (ptr->width) //&& ptr->width > ptr->prc)
	{
		if (ptr->prc && ptr->prc < ft_strlen(s))
		{
			i = ft_put(' ', ptr->width - ptr->prc);
			i += write(1, s, ptr->prc);
		}
		else
		{
			i = ft_put(' ', ptr->width - ft_strlen(s));
			i += write(1, s, ft_strlen(s));
		}
	}
	else if (ptr->prc)
		i = write(1, s, ptr->prc);
	else
		i = write(1, s, ft_strlen(s));
	(*f)++;
	return (i);
}