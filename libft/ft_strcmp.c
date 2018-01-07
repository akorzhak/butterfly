/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 11:47:20 by akorzhak          #+#    #+#             */
/*   Updated: 2017/10/30 11:47:23 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*f;
	unsigned char	*s;
	int				i;

	f = (unsigned char *)s1;
	s = (unsigned char *)s2;
	i = 0;
	while (f[i] == s[i] && f[i])
		i++;
	if (f[i] == '\0' && s[i] == '\0')
		return (0);
	else
		return (f[i] - s[i]);
}
