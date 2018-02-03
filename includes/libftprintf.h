/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:16:49 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 14:16:51 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h> //temp
# include <stdint.h> //for intmax_t && uintmax_t
# include <locale.h>

# define ABS(Value) (Value < 0) ? (-Value) : (Value)

typedef struct		s_flags
{
	char			min;
	char			plus;
	char			space;
	char			sharp;
	char			zero;
	int				width;	//intmax_t??
	int				prc;
	char			hh;
	char			ll;	
	char			h;
	char			l;
	char			j;
	char			z;
}					t_flags;

int				ft_printf(const char	*format, ...);
void			ft_addsize(t_flags *ptr, char **f);
void			ft_addflags(t_flags *ptr, char **f);
int				ft_printarg(t_flags *ptr, char **f, va_list arg);
int				ft_printnb(t_flags *ptr, char **f, va_list arg);
char			*ft_get_unb(t_flags *ptr, char **f, va_list arg);
char			*ft_get_snb(t_flags *ptr, char **f, va_list arg);
int				ft_unicode_s(t_flags *ptr, char **f, va_list arg);
int				ft_unicode_c(unsigned int c);
size_t			ft_intlen(unsigned int *str);
int				ft_printc(t_flags *ptr, char **f, va_list arg);
int				ft_prints(t_flags *ptr, char **f, va_list arg);
int 			ft_min(t_flags *p, char *nb);
int 			ft_put(char c, int nb);
int 			ft_zero_plus_space(t_flags *p, char *nb);

#endif
