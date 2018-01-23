/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:45:31 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/11 16:45:33 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int			size_of_arr(uintmax_t value, int base)
{
	int				len;

	len = 1;
	while (value >= base)
	{
		value /= base;
		len++;
	}
	return (len);
}

static char			*ft_u_itoa_base(uintmax_t value, int base, char a)
{
	char			*arr;
	int				len;

	len = size_of_arr(value, base);
	if ((arr = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	arr[len--] = '\0';
	(value == 0) ? (arr[len] = '0') : 0;
	while (value > 0)
	{
		if ((value % base) < 10)
			arr[len--] = (char)(value % base + '0');
		else
			arr[len--] = (char)(value % base - 10 + a);
		value /= base;
	}
	return (arr);
}

static char 	*ft_convert_to_char(uintmax_t nb, char **f)
{
	if (**f == 'o' || **f == 'O')
		return (ft_u_itoa_base(ABS(nb), 8, 'A'));	
	else if (**f == 'u' || **f == 'U')
		return (ft_u_itoa_base(ABS(nb), 10, 'A'));
	else if (**f == 'x' || **f == 'X')
		return (ft_u_itoa_base(ABS(nb), 16, 'A'));
	else
		return (ft_u_itoa_base(ABS(nb), 16, 'a'));
}

char	*ft_get_unb(t_flags *ptr, char **f, va_list arg) //"OoUuXxp"
{
	uintmax_t nb; //The C intmax_t and uintmax_t types can represent any value 
	//representable by any other integer types of the same signedness.
	if (ptr->h)
		nb = (unsigned short)(va_arg(arg, int));
	else if (ptr->hh)
		nb = (unsigned char)(va_arg(arg, int));
	else if (ptr->l)
		nb = va_arg(arg, unsigned long);
	else if (ptr->ll)
		nb = va_arg(arg, unsigned long long);
	else if (ptr->z)
		nb = va_arg(arg, size_t);
	else if (ptr->j)
		nb = va_arg(arg, uintmax_t);
	else
	{
		(ft_strchr("ouxp", **f)) ? (nb = va_arg(arg, unsigned int)) : 0;
		(ft_strchr("OUX", **f)) ? (nb = va_arg(arg, unsigned long)) : 0;
	}
	return (ft_convert_to_char(nb, f));
}
