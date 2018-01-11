/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akorzhak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 14:16:35 by akorzhak          #+#    #+#             */
/*   Updated: 2018/01/07 14:16:37 by akorzhak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		main(void)
{
	char str[] = "Hello, worldff%-+23.3hda";
//	printf("%s\n", "1 ----------------------  12345");
	printf("\nbm %d\n", ft_printf("Hello, worldff%-+23.3hd", 135));
//	printf("\nb %+-d\n", printf(str, -12345));
//	printf("%s\n", "2 ----------------------  12345");
//	printf("\nbm %d\n", ft_printf(str, -12345));
//	/*printf("\nb %-+d\n",*/ printf(str, 12345);
//	printf("\n");
//	/*printf("\nb %+-d\n",*/ printf(str, -12345);
//	printf("%s\n", "3 ---------------------  -+12345");
//	printf("\nbm %d\n", ft_printf(str, -+012345));
//	printf("\nb %d\n", printf(str, +012345));
	return (0);
}
