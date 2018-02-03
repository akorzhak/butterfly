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
	int a;
	int b;
	int c;
	int f;
	int j;
	int *s;

	a = 0;
	s = &a;
	setlocale(LC_ALL, "");

//  	printf("= bm %d\n", ft_printf("%C\n", L'是'));
// // 	printf("%s\n", "-------------------------");
// // 	
//  	printf("= bp %d\n", printf("%C\n", L'是'));
//  	printf("%s\n", "-------------------------");
// 	printf("= bm %d\n", ft_printf("%S\n", L"Привет мир!"));	
//  	printf("= bp %d\n", printf("%S\n", L"Привет мир!"));
//  	printf("%s\n", "-------------------------");
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
//	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%-10s\n", "hello"));
  	printf("= bp %d\n", printf("%-10s\n", "hello"));	
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%12.7s\n", "hello"));
  	printf("= bp %d\n", printf("%12.7s\n", "hello"));
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%12.2d\n", 12345));
  	printf("= bp %d\n", printf("%12.2d\n", 12345));
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%12.7d\n", 12345));
  	printf("= bp %d\n", printf("%12.7d\n", 12345));
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%12.1d\n", 12345));
  	printf("= bp %d\n", printf("%12.1d\n", 12345));
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%012s\n", "hello"));
  	printf("= bp %d\n", printf("%012s\n", "hello"));	
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%012d\n", 12345));
  	printf("= bp %d\n", printf("%012d\n", 12345));	
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%+012d\n", 12345));
  	printf("= bp %d\n", printf("%+012d\n", 12345));	
  	printf("%s\n", "-------------------------");
  	printf("= bm %d\n", ft_printf("%+012.10d\n", 12345));
  	printf("= bp %d\n", printf("%+012.10d\n", 12345));	

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
