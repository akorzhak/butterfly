/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:51:01 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:51:04 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int			ft_printc(t_flags *ptr, char **f, char c)
{
	char 	*str;
	int 	i;

	i = 0;
	if (c == 0 && (*f)++)
	{
		if (ptr->wd > 1)
		{
			if (ptr->zero && !ptr->min)
				i = ft_put('0', ptr->wd - 1);
			else if (!ptr->min)
				i = ft_put(' ', ptr->wd - 1);
		}
		i += write(1, "\0", 1);
		if (ptr->min)
			i += ft_put(' ', ptr->wd - 1);
	}
	else
	{
		str = ft_strnew(1);
		*str = c;
		ptr->space = 0;
		i = ft_prints(ptr, f, str);
		ft_strdel(&str);
	}
	return (i);
}
