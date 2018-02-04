/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:51:01 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:51:04 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_printarg(t_flags *ptr, char **f, va_list arg)
{
	int ret;
	char *str;

	ret = 1;
	if (**f == '%')
		ret = ft_print_percent(ptr, f);
	else if (ft_strchr("pdDioOuUxX", **f))
		ret = ft_printnb(ptr, f, arg);
	else if (**f == 'C' || (ptr->l && **f == 'c'))
		ret = ft_unicode_c(ptr, f, arg);
	else if (**f == 'S' || (ptr->l && **f == 's'))
		ret = ft_unicode_s(ptr, f, arg);	
	else if (**f == 'c')
		ret = ft_printc(ptr, f, va_arg(arg, int));
	else if (**f == 's')
		ret = ft_prints(ptr, f, va_arg(arg, char *));
	return (ret); //the number of read bytes
}
