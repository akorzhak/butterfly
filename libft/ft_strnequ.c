/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 14:27:19 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/07 08:56:11 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;
	int				i;

	if (s1 && s2)
	{
		f = (unsigned char *)s1;
		s = (unsigned char *)s2;
		i = 0;
		while ((f[i] == s[i]) && f[i] && s[i] && n)
		{
			i++;
			n--;
		}
		if ((f[i] == s[i]) || (!f[i] && !s[i]) || !n)
			return (1);
	}
	return (0);
}
