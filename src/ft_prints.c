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


int			ft_prints(t_flags *ptr, char **f, char *s)
{
	int i;

	i = 0;
	(s == NULL) ? s = "(null)" : 0;
	if (ptr->dot && !ptr->prc && **f != '%')
		s = "\0";
	if (ptr->min && ptr->wd > ft_strlen(s))
		i = ft_min(ptr, s, f, 0);
	else if (ptr->wd)
	{
		if (ptr->prc && ptr->prc < ft_strlen(s))
		{
			if (ptr->wd > ptr->prc)
				i = ft_put(' ', ptr->wd - ptr->prc);
			i += write(1, s, ptr->prc);
		}
		else
		{
			if (ptr->zero)
				i = ft_put('0', ptr->wd - ft_strlen(s));
			else
			{
				if (ptr->wd > ft_strlen(s))
					i = ft_put(' ', ptr->wd - ft_strlen(s));
			}
			i += write(1, s, ft_strlen(s));
		}
	}
	else if (ptr->prc && ptr->prc < ft_strlen(s))
		i = write(1, s, ptr->prc);
	else
		i = write(1, s, ft_strlen(s));
	(*f)++;
	return (i);
}