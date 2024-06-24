/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 12:29:15 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/17 12:29:17 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf_bonus.h"

//[-+ 0#][width][.precision][specifier]

int	main(void)
{
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                     NORMAL TEST                    //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");
	printf("\n");
//char
//YES: [-][width]
//undefined but WORK: [0]
//NOT WORK: [+][ ][#][.precision]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%c                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [c], 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%c]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%c]", 0));
	printf("\n[test 1: [3c], [5c], a, b]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("char: [%3c] and [%5c].", 'a', 'b'));
	printf("  >>> printf: return value is %d\n", printf("char: [%3c] and [%5c].", 'a', 'b'));
	printf("\n[test 2: [*c], 3, a]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%*c]", 3, 'a'));
	printf("  >>> printf: return value is %d\n", printf("[%*c]", 3, 'a'));
	printf("\n[test 3: [-c], [-5c], a, b]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-c] [%-5c]", 'a', 'b'));
	printf("  >>> printf: return value is %d\n", printf("[%-c] [%-5c]", 'a', 'b'));
	printf("\n");

//str
//YES: [-][width][.precision]
//undefined but WORK: [0]
//NOT WORK: [+][ ][#]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%s                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [s], hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%s]", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%s]", "hello"));
	printf("\n[test 1: [3s], [7s], [-7s], hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%3s], [%7s], [%-7s]", "hello", "hello", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%3s], [%7s], [%-7s]", "hello", "hello", "hello"));
	printf("\n[test 2: [0.3s], [7.3s], .0s, hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%1.3s], [%7.3s], [%.0s]", "hello", "hello", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%1.3s], [%7.3s], [%.0s]", "hello", "hello", "hello"));
	printf("\n[test 3: [-7.*s], [-7.*s], 3, hello, 7, hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-7.*s], [%-7.*s]", 3, "hello", 7, "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%-7.*s], [%-7.*s]", 3, "hello", 7, "hello"));
	printf("\n[test 4: [.s], hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%.s]", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%.s]", "hello"));
	printf("\n[test 5: null input [.2s], NULL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("null input [%.2s]", (char *)NULL));
	printf("  >>> printf: return value is %d\n", printf("null input [%.2s]", (char *)NULL));
	printf("\n[test 6: [1s], (char *)NULL, ' ', test, joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%1s, %1s, %1s, %1s]", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6"));
	printf("  >>> printf: return value is %d\n", printf("[%1s, %1s, %1s, %1s]", (char *)NULL, "", "test", "joihwhhgsdkhksdgsdg\t\v\n\r\f\a25252\b6"));
	printf("\n");


//decimal base 10,
//YES: [-][width][+][ ][0][.precision]
//undefined but WORK: [#]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%d                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [d], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%d]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%d]", 0));
	printf("\n[test 1: [-d], [-3d], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-d], [%-3d]", 42, 42));
	printf("  >>> printf: return value is %d\n", printf("[%-d], [%-3d]", 42, 42));
	printf("\n[test 2: [.5d], [5.5d], 42, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%.5d], [%5.5d]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%.5d], [%5.5d]", 42, -42));
	printf("\n[test 3: [ 3.*d], [*d], 1, 42, 5, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[% 3.*d], [%*d]", 1, 42, 5, -42));
	printf("  >>> printf: return value is %d\n", printf("[% 3.*d], [%*d]", 1, 42, 5, -42));
	printf("\n[test 4: [+d], [0d], [ d], INT_MAX, INT_MIN, UINT_MAX)\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+d], [%0d], [% d]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%+d], [%0d], [% d]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 5: [.0d], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n[test 6: [0 100.0d], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d, %0 100.0d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n");

//integer base 10
//YES: [-][width][+][ ][0][.precision]
//undefined but WORK: [#]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%i                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [i], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%i]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%i]", 0));
	printf("\n[test 1: [-i], [-3i], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-i], [%-3i]", 42, 42));
	printf("  >>> printf: return value is %d\n", printf("[%-i], [%-3i]", 42, 42));
	printf("\n[test 2: [.5i], [5.5i], 42, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%.5i], [%5.5i]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%.5i], [%5.5i]", 42, -42));
	printf("\n[test 3: [ 3.*i], [*i], 1, 42, 5, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[% 3.*i], [%*i]", 1, 42, 5, -42));
	printf("  >>> printf: return value is %d\n", printf("[% 3.*i], [%*i]", 1, 42, 5, -42));
	printf("\n[test 4: [+i], [0i], [ i], INT_MAX, INT_MIN, UINT_MAX)\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+i], [%0i], [% i]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%+i], [%0i], [% i]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 5: [.0i], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%.0i, %.0i, %.0i, %.0i, %.0i, %.0i, %.0i, %.0i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%.0i, %.0i, %.0i, %.0i, %.0i, %.0i, %.0i, %.0i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n[test 6: [0 100.0i], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i, %0 100.0i", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n");

//unsigned decimal base 10
//YES: [-][width][0][.precision]
//undefined but WORK: [+][ ][#]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%u                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [u], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%u]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%u]", 0));
	printf("\n[test 1: [-u], [-3u], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-u], [%-3u]", 42, 42));
	printf("  >>> printf: return value is %d\n", printf("[%-u], [%-3u]", 42, 42));
	printf("\n[test 2: [.5u], [5.5u], 42, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%.5u], [%5.5u]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%.5u], [%5.5u]", 42, -42));
	printf("\n[test 3: [3.*u], [*u], 1, 42, 5, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%3.*u], [%*u]", 1, 42, 5, -42));
	printf("  >>> printf: return value is %d\n", printf("[%3.*u], [%*u]", 1, 42, 5, -42));
	printf("\n[test 4: [0.3u], [0u], [2.5u], INT_MAX, INT_MIN, UINT_MAX)\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%0.3u], [%0u], [%2.5u]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%0.3u], [%0u], [%2.5u]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 5: [.0u], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%.0u, %.0u, %.0u, %.0u, %.0u, %.0u, %.0u, %.0u", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%.0u, %.0u, %.0u, %.0u, %.0u, %.0u, %.0u, %.0u", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n");

//lowercase hexadecimal base 16
//YES: [-][#][0][width][.precision]
//undefined but WORK: [+][ ]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%x                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [0x], 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%0x]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%0x]", 0));
	printf("\n[test 1: [-x], [-15x], 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-x], [%-15x]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%-x], [%-15x]", 42, -42));
	printf("\n[test 2: [5.7x], [.0x], 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5.7x], [%.0x]", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("[%5.7x], [%.0x]", 042, 0x42));
	printf("\n[test 3: [x], INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%x], [%x], [%x]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%x], [%x], [%x]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 4: [#.x], 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x]", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x], [%#.x]", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("\n");

//upper hexadecimal base 16
//YES: [-][#][0][width][.precision]
//undefined but WORK: [+][ ]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%X                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [0X], 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%0X]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%0X]", 0));
	printf("\n[test 1: [-X], [-15X], 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-X], [%-15X]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%-X], [%-15X]", 42, -42));
	printf("\n[test 2: [5.7X], [0X], 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5.7X], [%.0X]", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("[%5.7X], [%.0X]", 042, 0x42));
	printf("\n[test 3: [X], INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%X], [%X], [%X]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%X], [%X], [%X]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 4: [#.X], 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X]", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X], [%#.X]", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("\n");

//pointer
//YES: [-][width]
//undefined but WORK: [+][ ][0][#][.precision]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%p                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 1: [p], *0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%p]", (void *)0));
	printf("  >>> printf: return value is %d\n", printf("[%p]", (void *)0));
	printf("\n[test 2: [-p], [-20p], *42, *-42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-p], [%-20p]", (void *)42, (void *)42));
	printf("  >>> printf: return value is %d\n", printf("[%-p], [%-20p]", (void *)42, (void *)42));
	printf("\n[test 3: [7p], [p], *INT_MAX, *INT_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%7p], [%p]", (void *)INT_MAX, (void *)INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%7p], [%p]", (void *)INT_MAX, (void *)INT_MAX));
	printf("\n[test 4: [5p], [20p], *LONG_MAX, *LONG_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5p], [%20p]", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("  >>> printf: return value is %d\n", printf("[%5p], [%20p]", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("\n[test 5: [20p], [p], *ULONG_MAX, *-ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-20p], [%p]", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%-20p], [%p]", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf("\n[test 1: [p], *0 *0xABCDE, *ULONG_MAX, *LONG_MIN, *-1, *-2352]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%p], [%p], [%p], [%p], [%p], [%p]", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352));
	printf("  >>> printf: return value is %d\n", printf("[%p], [%p], [%p], [%p], [%p], [%p]", (void *)0, (void *)0xABCDE, (void *)ULONG_MAX, (void *)LONG_MIN, (void *)-1, (void *)-2352));
	printf("\n");


//percent sign
//YES: [-][width]
//undefined but WORK:
//NOT WORK: [0][+][ ][#][.precision]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%%%                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 1: 2x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%%]"));
	printf("  >>> printf: return value is %d\n", printf("[%%]"));
	printf("\n[test 1: %%5%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5%]"));
	printf("  >>> printf: return value is %d\n", printf("[%5%]"));
	printf("\n[test 1: %%-5%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%-5%]"));
	printf("  >>> printf: return value is %d\n", printf("[%-5%]"));
	printf("\n[test 2: 2x%%, 4x%%, 6x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%%, %%%%, %%%%%%"));
	printf("  >>> printf: return value is %d\n", printf("%%, %%%%, %%%%%%"));
	printf("\n");

	printf("\n// ************************************************** //\n");

/*
//undefined test
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                   UNDEFINED TEST                   //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

//char
//YES: [-][width]
//undefined but WORK: [0]
//NOT WORK: [+][ ][#][.precision]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%c                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: 0c, 05c, -05c, a]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%0c], [%05c], [%-05c]", 'a', 'a', 'a'));
	printf("  >>> printf: return value is %d\n", printf("[%0c], [%05c], [%-05c]", 'a', 'a', 'a'));
	printf("\n[test 1: 3-0+c, a]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%3-0+c]", 'a'));
	printf("  >>> printf: return value is %d\n", printf("[%3-0+c]", 'a'));
	printf("\n[test 2: #-0.5c, a]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%#-0.5c]", 'a'));
	printf("  >>> printf: return value is %d\n", printf("[%#-0.5c]", 'a'));
	printf("\n");

//str
//YES: [-][width][.precision]
//undefined but WORK: [0]
//NOT WORK: [+][ ][#]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%s                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: +-3#s, hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+-3#s]", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%+-3#s]", "hello"));
	printf("\n[test 1: 03s,  7s, -#0.7s, hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%03s], [% 7s], [%-#0.7s]", "hello", "hello", "hello"));
	printf("  >>> printf: return value is %d\n", printf("[%03s], [% 7s], [%-#0.7s]", "hello", "hello", "hello"));
	printf("\n");

//decimal base 10,
//YES: [-][width][+][ ][0][.precision]
//undefined but WORK: [#]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%d                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [5 +-d], [3#-3d], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5 +-d], [%3#-3d]", 42, 42));
	printf("  >>> printf: return value is %d\n", printf("[%5 +-d], [%3#-3d]", 42, 42));
	printf("\n[test 1: [05d], [#d], 42, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%05d], [%#d]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%05d], [%#d]", 42, -42));
	printf("\n[test 2: [d], 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%d]", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("[%d]", 9223372036854775807LL));
	printf("\n[test 3: [d], LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%d], [%d], [%d]", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%d], [%d], [%d]", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("\n");

//integer base 10
//YES: [-][width][+][ ][0][.precision]
//undefined but WORK: [#]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%i                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [5 +-i], [3#-3i], 0\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5 +-i], [%3#-3i]", 42, 42));
	printf("  >>> printf: return value is %d\n", printf("[%5 +-i], [%3#-3i]", 42, 42));
	printf("\n[test 1: [05i], [#i], 42, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%05i], [%#i]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%05i], [%#i]", 42, -42));
	printf("\n[test 2: [i], 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%i]", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("[%i]", 9223372036854775807LL));
	printf("\n[test 3: [i], LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%i], [%i], [%i]", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%i], [%i], [%i]", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("\n");

//unsigned decimal base 10
//YES: [-][width][0][.precision]
//undefined but WORK: [+][ ][#]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%u                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [ 3.*u], [*u], 1, 42, 5, -42\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[% 3.*u], [%+*u]", 1, 42, 5, -42));
	printf("  >>> printf: return value is %d\n", printf("[% 3.*u], [%+*u]", 1, 42, 5, -42));
	printf("\n[test 1: [ 0.3u], [#0u], [5+02.5u], INT_MAX, INT_MIN, UINT_MAX)\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[% 0.3u], [%#0u], [%5+02.5u]", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[% 0.3u], [%#0u], [%5+02.5u]", INT_MAX, INT_MIN, UINT_MAX));
	printf("\n[test 2: [0 100.0u], 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u, %0 100.0u", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX));
	printf("\n");

//lowercase hexadecimal base 16
//YES: [-][#][0][width][.precision]
//undefined but WORK: [+][ ]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%x                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: +0x, 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+0x]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%+0x]", 0));
	printf("\n[test 1: - x, -15 x, 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%- x], [%-15 x]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%- x], [%-15 x]", 42, -42));
	printf("\n[test 2: + 5.7x, 5 .0x, 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+ 5.7x], [%5 .0x]", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("[%+ 5.7x], [%5 .0x]", 042, 0x42));
	printf("\n");

//lowercase hexadecimal base 16
//YES: [-][#][0][width][.precision]
//undefined but WORK: [+][ ]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%X                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: +0X, 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+0X]", 0));
	printf("  >>> printf: return value is %d\n", printf("[%+0X]", 0));
	printf("\n[test 1: - X, -15 X, 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%- x], [%-15 X]", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("[%- x], [%-15 X]", 42, -42));
	printf("\n[test 2: + 5.7X, 5 .0X, 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+ 5.7x], [%5 .0X]", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("[%+ 5.7x], [%5 .0X]", 042, 0x42));
	printf("\n");

//pointer
//YES: [-][width]
//undefined but WORK: [+][ ][0][#][.precision]
//NOT WORK:
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%p                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: [+p], [+ p], *42, *-42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%+p], [%+ p]", (void *)42, (void *)42));
	printf("  >>> printf: return value is %d\n", printf("[%+p], [%+ p]", (void *)42, (void *)42));
	printf("\n[test 1: [0p], [#p], *INT_MAX, *INT_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%0p], [%#p]", (void *)INT_MAX, (void *)INT_MAX));
	printf("  >>> printf: return value is %d\n", printf("[%0p], [%#p]", (void *)INT_MAX, (void *)INT_MAX));
	printf("\n[test 2: [5.5p], [20.5p], *LONG_MAX, *LONG_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("[%5.5p], [%20.5p]", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("  >>> printf: return value is %d\n", printf("[%5.5p], [%20.5p]", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("\n");

//percent sign
//YES: [-][width]
//undefined but WORK:
//NOT WORK: [0][+][ ][#][.precision]
	printf("// ************************************************** //\n");
	printf("//                                                    //\n");	
	printf("//                         %%%%                         //\n");
	printf("//                                                    //\n");
	printf("// ************************************************** //\n");

	printf("\n[test 0: 1x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%"));
	printf("  >>> printf: return value is %d\n", printf("%"));
	printf("\n[test 1: 3x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%%%"));
	printf("  >>> printf: return value is %d\n", printf("%%%"));
	printf("\n");
	
	printf("\n// ************************************************** //\n");
*/
	return (0);
}