/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:22:26 by akorzhak          #+#    #+#             */
/*   Updated: 2017/11/03 13:22:30 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *arr;

	if (!(arr = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(arr, (size + 1));
	return (arr);
}
