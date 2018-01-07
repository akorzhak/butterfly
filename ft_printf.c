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

#include "libftprintf.h"

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
		w = ft_strsub(*f, 0, param); //w = ft_strncpy(ft_strnew(width), *f, width); //width written as char *
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

int		ft_readparams(char **format, va_list arg) //everything after %, excluding %
{
	t_param *ptr;
	int i;
	char *f;
	if (!(ptr = (t_param *)ft_memalloc(sizeof(t_param))))
		return (0);
	ptr->fl = 0;
	ptr->wd = 0;
	ptr->pr = 0;
	ptr->len = 0;
	i = 0;
	f = *format;
	while (*f == '-' || *f == '+' || *f == ' ' || *f == '#' || *f == '0')
		f++;
	if (f - *format)
		ptr->fl = ft_strsub(*format, 0, f - *format);
	if ((*f >= '0' && *f <= '9') || *f == '*')
		ptr->wd = ft_getint(&f, arg, ptr->wd);
	if ((*f == '.') && (f++))
		ptr->pr = ft_getint(&f, arg, ptr->pr);
	(*f == 'h' && *(f + 1) == 'h') ? (ptr->len = 'H', f = f + 2) : 0; //hh
	(*f == 'l' && *(f + 1) == 'l') ? (ptr->len = 'U', f = f + 2) : 0; //ll
	(*f == 'h' || *f == 'l' || *f == 'j'|| *f == 'z' || *f == 't' ||
	*f == 'L') ? (ptr->len = *f, f++) : 0;
	// printf("\nflag: %s\n", ptr->fl);
	// printf("width: %d\n", ptr->wd);
	// printf("precision: %d\n", ptr->pr);
	// printf("length: %c\n", ptr->len);
	return (ft_printarg(ptr, f, arg));
}

int		ft_printf(const char *format, ...)
{
	char *fstr;
	int i;
	va_list arg;
	int flag;

	va_start(arg, format);
	fstr = (char *)format;
	flag = 0;
	i = 0;
	while (*fstr)
	{
		while (*fstr != '%' && *fstr)
			ft_putchar(*fstr++);	
		if (*fstr == '%' && *(fstr + 1) == '%') //the 2nd %
		{
			ft_putchar('%');  //(*fstr++);
			fstr = fstr + 2;
			flag++;
		}
		else if (*fstr == '%' && *(fstr + 1) != '%')
		{
			i = fstr - format;
		//	printf("%s\n", "Hello");
			fstr++;
		//	printf("%s\n", fstr);
		//	printf("%d\n", i);
			i += ft_readparams(&fstr, arg);
			fstr++;
		}
		if (!*fstr) //fstr has to plus itself no matter what
		{
			(!i) ? (i = fstr - format - flag) : 0;
			return (i);
		}
	}
	va_end(arg);
	return (i);
}
