/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 11:46:53 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/01 11:46:56 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*f;
	unsigned char	*s;
	int				i;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while (f[i] == s[i] && f[i] && n--)
		i++;
	if (!n)
		return (0);
	else
		return (f[i] - s[i]);
}
