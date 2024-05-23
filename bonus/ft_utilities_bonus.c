/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:17:43 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/21 17:17:49 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar(int c, int n, t_data *data)
{
	while (n)
	{
		if (write(1, &c, 1) != 1)
		{
			data->len = -1;
			return (-1);
		}
		data->len++;
		n--;
	}
	return (1);
}

int	my_strchr(const char *s, char c)
{
	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL || !*s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_putstr(char *s, int precision, t_data *data)
{
	if (precision < 0)
		return (-1);
	while (precision-- && *s)
	{
		if (ft_putchar(*s, 1, data) == -1)
			return (-1);
		s++;
	}
	return (1);
}
