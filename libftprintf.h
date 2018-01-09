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

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h> //temp

//# define BUFF_SIZE 8

typedef struct		s_flags
{
	char			min;
	char			plus;
	char			space;
	char			sharp;
	char			zero;
	int				width;	//intmax_t??
	int				prec;
	char			hh;
	char			ll;	
	char			h;
	char			l;
	char			j;
	char			z;
	char			t;
	char			L;
}					t_flags;

int		ft_printf(const char	*format, ...);
int		ft_printarg(t_param *ptr, char **f, va_list arg);
//int		ft_printint(t_param params, char **f, va_list arg);

//int		get_next_line(const int fd, char **line); */

#endif
