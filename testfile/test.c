/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:45:21 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/09 11:47:57 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	//char
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%c                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: a]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%c", 'a'));
	printf("  >>> printf: return value is %d\n", printf("%c", 'a'));
	printf("\n[test 2: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf(" %c", '0'));
	printf("  >>> printf: return value is %d\n", printf(" %c", '0'));
	printf("\n[test 3: a, b]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf(" %c, %c", 'a', 'b'));
	printf("  >>> printf: return value is %d\n", printf(" %c, %c", 'a', 'b'));
	
	printf("\n");

	//str
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%s                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: hello]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%s", "hello"));
	printf("  >>> printf: return value is %d\n", printf("%s", "hello"));
	printf("\n[test 2: ""]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%s", ""));
	printf("  >>> printf: return value is %d\n", printf("%s", ""));
	printf("\n[test 3: hello, hey]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf(" %s, %s", "hello", "hey"));
	printf("  >>> printf: return value is %d\n", printf(" %s, %s", "hello", "hey"));
	printf("\n[test 4: NULL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("null input %s", NULL));
	printf("  >>> printf: return value is %d\n", printf("null input %s", NULL));
	
	printf("\n");

	//pointer
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%p                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: *0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%p", (void *)0));
	printf("  >>> printf: return value is %d\n", printf("%p", (void *)0));
	printf("\n[test 2: *42, *-42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%p, %p", (void *)42, (void *)-42));
	printf("  >>> printf: return value is %d\n", printf("%p, %p", (void *)42, (void *)-42));
	printf("\n[test 3: *INT_MAX, *INT_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%p, %p", (void *)INT_MAX, (void *)INT_MIN));
	printf("  >>> printf: return value is %d\n", printf("%p, %p", (void *)INT_MAX, (void *)INT_MIN));
	printf("\n[test 4: *LONG_MAX, *LONG_MIN]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%p, %p", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("  >>> printf: return value is %d\n", printf("%p, %p", (void *)LONG_MAX, (void *)LONG_MIN));
	printf("\n[test 5: *ULONG_MAX, *-ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%p, %p", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%p, %p", (void *)ULONG_MAX, (void *)-ULONG_MAX));
	
	printf("\n");
	

	//decimal base 10
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%d                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d", 0));
	printf("  >>> printf: return value is %d\n", printf("%d", 0));
	printf("\n[test 2: 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d, %d", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("%d, %d", 42, -42));
	printf("\n[test 3: 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d, %d", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("%d, %d", 042, 0x42));
	printf("\n[test 4: INT_MAX, INT_MIN, UINT_MAX)]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d, %d, %d", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%d, %d, %d", INT_MAX, INT_MIN, UINT_MAX));
/*
	printf("\n[test 5: 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("%d", 9223372036854775807LL));
	printf("\n[test 6: LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%d, %d, %d", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%d, %d, %d", LONG_MAX, LONG_MIN, ULONG_MAX));
*/
	printf("\n");

	//integer base 10
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%i                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i", 0));
	printf("  >>> printf: return value is %d\n", printf("%i", 0));
	printf("\n[test 2: 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i, %i", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("%i, %i", 42, -42));
	printf("\n[test 3: 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i, %i", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("%i, %i", 042, 0x42));
	printf("\n[test 4: INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i, %i, %i", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%i, %i, %i", INT_MAX, INT_MIN, UINT_MAX));
/*
	printf("\n[test 5: 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("%i", 9223372036854775807LL));
	printf("\n[test 6: LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i, %i, %i", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%i, %i, %i", LONG_MAX, LONG_MIN, ULONG_MAX));
*/
	printf("\n");
	
	//unsigned decimal base 10
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%u                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%u", 0));
	printf("  >>> printf: return value is %d\n", printf("%u", 0));
	printf("\n[test 2: 42, -42)]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%u, %u", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("%u, %u", 42, -42));
	printf("\n[test 3: 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%u, %u", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("%u, %u", 042, 0x42));
	printf("\n[test 4: INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%u, %u, %u", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%u, %u, %u", INT_MAX, INT_MIN, UINT_MAX));
/*
	printf("\n[test 5: 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("%i", 9223372036854775807LL));
	printf("\n[test 6: LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%i, %i, %i", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%i, %i, %i", LONG_MAX, LONG_MIN, ULONG_MAX));
*/
	printf("\n");


	//lowercase hexadecimal base 16
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%x                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x", 0));
	printf("  >>> printf: return value is %d\n", printf("%x", 0));
	printf("\n[test 2: 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x, %x", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("%x, %x", 42, -42));
	printf("\n[test 3: 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x, %x", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("%x, %x", 042, 0x42));
	printf("\n[test 4: INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x, %x, %x", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%x, %x, %x", INT_MAX, INT_MIN, UINT_MAX));

	printf("\n[test 5: 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("%x", 9223372036854775807LL));
	printf("\n[test 6: LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%x, %x, %x", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%x, %x, %x", LONG_MAX, LONG_MIN, ULONG_MAX));

	printf("\n");
	
	//uppercase hexadecimal base 16
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%X                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");
	
	printf("\n[test 1: 0]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X", 0));
	printf("  >>> printf: return value is %d\n", printf("%X", 0));
	printf("\n[test 2: 42, -42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X, %X", 42, -42));
	printf("  >>> printf: return value is %d\n", printf("%X, %X", 42, -42));
	printf("\n[test 3: 042, 0x42]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X, %X", 042, 0x42));
	printf("  >>> printf: return value is %d\n", printf("%X, %X", 042, 0x42));
	printf("\n[test 4: INT_MAX, INT_MIN, UINT_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X, %X, %X", INT_MAX, INT_MIN, UINT_MAX));
	printf("  >>> printf: return value is %d\n", printf("%X, %X, %X", INT_MAX, INT_MIN, UINT_MAX));

	printf("\n[test 5: 9223372036854775807LL]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X", 9223372036854775807LL));
	printf("  >>> printf: return value is %d\n", printf("%X", 9223372036854775807LL));
	printf("\n[test 6: LONG_MAX, LONG_MIN, ULONG_MAX]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%X, %X, %X", LONG_MAX, LONG_MIN, ULONG_MAX));
	printf("  >>> printf: return value is %d\n", printf("%X, %X, %X", LONG_MAX, LONG_MIN, ULONG_MAX));

	printf("\n");

	//percent sign
	printf("/* ************************************************** */\n");
	printf("/*                                                    */\n");	
	printf("/*                         %%%%                         */\n");
	printf("/*                                                    */\n");
	printf("/* ************************************************** */\n");

	printf("\n[test 1: 2x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%%"));
	printf("  >>> printf: return value is %d\n", printf("%%"));
	printf("\n[test 2: 2x%%, 4x%%, 6x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%%, %%%%, %%%%%%"));
	printf("  >>> printf: return value is %d\n", printf("%%, %%%%, %%%%%%"));

	printf("\n[test 3: 1x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%"));
	printf("  >>> printf: return value is %d\n", printf("%"));
	printf("\n[test 4: 3x%%]\n");
	printf("  >>> ft_printf: return value is %d\n", ft_printf("%%%"));
	printf("  >>> printf: return value is %d\n", printf("%%%"));

	printf("\n/* ************************************************** */\n");

	return (0);
}
