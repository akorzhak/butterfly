/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:47:24 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/10 19:47:27 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_addsize(t_flags *ptr, char **f)
{
	while (**f)
	{
		if (**f == 'h' && **(f + 1) == 'h') //*(*f++ + 1)
		{
			ptr->hh = 1;
			(*f)++;
		}
		else if (**f == 'h')
			ptr->h = 1;
		else if (**f == 'l' && **(f + 1) == 'l')
		{
			ptr->ll = 1;
			(*f)++;
		}
		else if (**f == 'l')
			ptr->l = 1;
		else if (**f == 'j')
			ptr->j = 1;
		else if (**f == 'z')
			ptr->z = 1;
		else
			return ;
		(*f)++;
	}
}
