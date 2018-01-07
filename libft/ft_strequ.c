/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:23:34 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/04 14:23:37 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*f;
	unsigned char	*s;
	int				i;

	if (s1 && s2)
	{
		f = (unsigned char *)s1;
		s = (unsigned char *)s2;
		i = 0;
		while (f[i] == s[i] && f[i])
			i++;
		if (f[i] == '\0' && s[i] == '\0')
			return (1);
	}
	return (0);
}
