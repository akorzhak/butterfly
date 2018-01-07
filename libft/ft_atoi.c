/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 21:29:55 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/27 21:29:57 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	unsigned long int	res;
	int					min;

	res = 0;
	min = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '+' || *str == '-')
		(*(str++) == '-') ? (min = -1) : 0;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *(str++) - '0';
	if (res >= 9223372036854775807 && min == 1)
		return (-1);
	else if (res > 9223372036854775807 && min == -1)
		return (0);
	return ((int)(res * min));
}
