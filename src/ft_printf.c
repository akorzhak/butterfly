/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:16:26 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 14:16:29 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int		ft_getint(char **f, va_list arg, int param)
{
	char *w;
	char *temp;

	temp = *f;
	while (*temp >= '0' && *temp <= '9')
	{
		param++;
		temp++;
	}
	if (param)
	{
		w = ft_strsub(*f, 0, param);
		param = ft_atoi(w);
		ft_strdel(&w);
	}
	*f = temp;		
	if (**f == '*')
	{
		param = va_arg(arg, int);
		*f = ++*f;
	}
	return (param);
}

int		ft_readparams(char **f, va_list arg) //everything after %, excluding %
{
	t_flags *ptr;

	ptr = (t_flags *)ft_memalloc(sizeof(t_flags));
	(*f)++;
	if (!**f)
		return (0);
	if (ft_strchr("-+#0 ", **f))
		ft_addflags(ptr, f);
	if ((**f >= '0' && **f <= '9') || **f == '*')
		ptr->wd = ft_getint(f, arg, ptr->wd);
	if ((**f == '.') && ((*f)++))
	{
		ptr->dot = 1;
		ptr->prc = ft_getint(f, arg, ptr->prc);
	}
	if (ft_strchr("hljztL", **f))
		ft_addsize(ptr, f);
	if (!ft_strchr("cCsSpdDioOuUxX%", **f))
		return (0);
	return (ft_printarg(ptr, f, arg));
} 

int		ft_printf(const char *format, ...)
{
	char *s;
	char *c;
	int i;
	va_list arg;

	s = (char *)format;
	i = 0;
	va_start(arg, format);
	while (ft_strchr(s, '%') && (c = ft_strchr(s, '%')))
	{
		if (c - s > 0)
			i += write(1, s, c - s);
		i += ft_readparams(&c, arg); //%...
		s = c;
	}
	va_end(arg);
	return (i + write(1, s, ft_strlen(s)));
}
