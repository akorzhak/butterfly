/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:04:25 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:27 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_addflags(t_flags *ptr, char **f)
{
	while (**f)
	{
		if (**f == '-')
			ptr->min = 1;
		else if (**f == '+')
			ptr->plus = 1;
		else if (**f == ' ')
			ptr->space = 1;
		else if (**f == '#')
			ptr->sharp = 1;
		else if (**f == '0')
			ptr->zero = 1;
		else
			return ;
		(*f)++;
	}
}
