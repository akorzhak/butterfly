/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:30:57 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/06 11:30:59 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned char octet)
{
	int n;

	n = 128;
	while (n >= 1)
	{
		if (octet >= n)
		{
			ft_putchar('1');
			octet -= n;
		}
		else
			ft_putchar('0');
		n /= 2;
	}
}
