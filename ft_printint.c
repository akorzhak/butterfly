/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:54:14 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 16:54:17 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nblen(int nb, char fg)
{
	int n;
	int i;

	n = 1;
	i = 0;
	if ((fg == '+' || fg == ' ') && nb > 0)
	{
		i++;
	}
	if (nb < 0)
	{
		nb = -nb;
		i++; //for -
	}
	while ((nb / n) > 0)
	{
		i++;
		n *= 10;
	}
	return (i);
}

int		ft_printint(t_param *ptr, char **f, va_list arg)
{
	void nb; 
	int i;
	int len;

	nb = ft_getnb(arg, int, ptr->len);
	len = ft_nblen(nb, fg);
	if ((wd > len) && (wd >= pr))
		return (wd);
	else if ((pr > len) && (pr > wd))
		return (pr);
	return (len);
