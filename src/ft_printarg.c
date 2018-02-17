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

static int	ft_print_undef_spec(t_flags *ptr, char **f)
{
	int		ret;

	ret = 0;
	if (ptr->wd)
	{
		if (ptr->min)
			ret = write(1, *f, 1) + ft_put(' ', ptr->wd - 1);
		else
		{
			if (ptr->zero)
				ret = ft_put('0', ptr->wd - 1) + write(1, *f, 1);
			else
				ret = ft_put(' ', ptr->wd - 1) + write(1, *f, 1);
		}
		(*f)++;
	}
	return (ret);
}

int			ft_printarg(t_flags *ptr, char **f, va_list arg)
{
	int		ret;
	char	*str;

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
	else
		ret = ft_print_undef_spec(ptr, f);
	return (ret);
}
