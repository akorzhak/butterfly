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

int		ft_handlecase(t_flags *ptr, char *s, size_t len)
{
	int i;

	i = 0;
	if (ptr->prc && ptr->prc < len)
	{
		if (ptr->wd > ptr->prc)
			i = ft_put(' ', ptr->wd - ptr->prc);
		i += write(1, s, ptr->prc);
	}
	else
	{
		if (ptr->zero)
			i = ft_put('0', ptr->wd - len);
		else
		{
			if (ptr->wd > len)
				i = ft_put(' ', ptr->wd - len);
		}
		i += write(1, s, len);
	}
	return (i);
}

int		ft_prints(t_flags *ptr, char **f, char *s)
{
	int		i;
	size_t	len;

	(s == NULL) ? s = "(null)" : 0;
	if (ptr->dot && !ptr->prc && **f != '%')
		s = "\0";
	len = ft_strlen(s);
	if (ptr->min && ptr->wd > len)
		i = ft_min(ptr, s, f, 0);
	else if (ptr->wd)
		i = ft_handlecase(ptr, s, len);
	else if (ptr->prc && ptr->prc < len)
		i = write(1, s, ptr->prc);
	else
		i = write(1, s, len);
	(*f)++;
	return (i);
}
