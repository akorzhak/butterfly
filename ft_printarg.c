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

#include "libftprintf.h"

int		ft_printarg(t_flags *ptr, char **f, va_list arg)
{
	int ret;

	ret = 0;
	if (**f == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (ft_strchr("pdDioOuUxX", **f))
		ret = ft_printnb(ptr, f, arg);
	//printf("qqqqq%d\n", ret);
	/*else if (**f == 'c')
		ft_printchar(fl, wd, pr, len, f, arg);
	else if (**f == 's') 
		ft_printstr(fl, wd, pr, len, f, arg);
	else if (**f == 'u' || **f == 'o' || **f == 'x' || **f == 'X')
		ft_printuox(fl, wd, pr, len, f, arg);
	else if (**f == 'f' || **f == 'F'  || **f == 'e' || **f == 'E' || 
		**f == 'g' || **f == 'G' || **f == 'a' || **f == 'A')
		ft_printfega(fl, wd, pr, len, f, arg);
	else if (**f == 'p')
		ft_printp(fl, wd, pr, len, f, arg);
	else if (**f == 'n')
		ft_printn(fl, wd, pr, len, f, arg);
	else //pointless for now
		return (0); */
	return (ret); //the number of read bytes
}
