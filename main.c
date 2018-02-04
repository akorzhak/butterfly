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

#include "includes/libftprintf.h"

int		main(void)
{
	int i;
	unsigned long l;
	char *str;

	setlocale(LC_ALL, "");

	printf("%s\n", "------------------------------------------------");
	printf("= bm %d\n", ft_printf("%+d", 42));
	printf("= bp %d\n", printf("%+d", 42));
	// printf("%s\n", "------------------------------------------------");
	// printf("= bm %d\n", ft_printf("%p", &l));
	// printf("= bp %d\n", printf("%p", &l));
	// printf("%s\n", "------------------------------------------------");
	// printf("= bm %d\n", ft_printf("%p", &str));
	// printf("= bp %d\n", printf("%p", &str));
	// printf("%s\n", "------------------------------------------------");
	// printf("= bm %d\n", ft_printf("%p", &strlen));
	// printf("= bp %d\n", printf("%p", &strlen));
	// printf("%s\n", "------------------------------------------------");
	// printf("= bm %d\n", ft_printf("%p", 0));
	// printf("= bp %d\n", printf("%p", 0));
	// printf("%s\n", "------------------------------------------------");
	// printf("= bm %d\n", ft_printf("{%s}", ""));
	// printf("= bp %d\n", printf("{%s}", ""));

//   	printf("= bm %d\n", ft_printf("%6.1C\n", L'是'));
// // // 	printf("%s\n", "-------------------------");
// // // 	
//   	printf("= bp %d\n", printf("%6.1C\n", L'是'));
//   	printf("%s\n", "-------------------------");
// 	printf("= bm %d\n", ft_printf("%23S\n", L"是是是вет мир!"));	
//  	printf("= bp %d\n", printf("%23S\n", L"是是是вет мир!"));
// //  	printf("%s\n", "-------------------------");
//  	printf("= bm %d\n", ft_printf("%c\n", 'a'));
//  	printf("= bp %d\n", printf("%c\n", 'a'));
//   	printf("%s\n", "-------------------------");
//   	printf("= bm %d\n", ft_printf("%s\n", "hello"));
//   	printf("= bp %d\n", printf("%s\n", "hello"));
//   	printf("%s\n", "-------------------------");
//   	printf("= bm %d\n", ft_printf("%c\n", 'z'));
//   	printf("= bp %d\n", printf("%c\n", 'z'));
//   	printf("%s\n", "-------------------------");
// 	printf("= bm %d\n", ft_printf("%lc\n", L'П'));
//  	printf("= bp %d\n", printf("%lc\n", L'П'));
//  	printf("%s\n", "-------------------------");
// 	printf("= bm %d\n", ft_printf("%ls\n", L"Привет"));
//  	printf("= bp %d\n", printf("%ls\n", L"Привет"));

// 	printf("= bp %d\n", printf("%S\n", L"Привет мир!"));
// 	
// //	char str[] = "Hello, worldff%-+23.3hda";
// //	printf("%s\n", "1 ----------------------  12345");
// 	printf("= bm %d\n", ft_printf("Hello, worldff %p\n", &s));
// 	printf("= bp %d\n", printf("Hello, worldff %p\n", &s));
// 	printf("%s\n", "------------------------------------------------");
// 	printf("= bm %d\n", ft_printf("Hello, worldff %x\n", -182323445));
// 	printf("= bm %d\n", ft_printf("Hello, worldff %x\n", -182323445));
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
