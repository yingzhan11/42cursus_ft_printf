/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:37:16 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/22 11:16:37 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_str_spaces(t_data *data, char *s)
{
	int	strlen;
	int	padding;

	strlen = ft_strlen(s);
	padding = 0;
	if (data->fmt.width > 0)
	{
		if (data->fmt.precision >= 0)
		{
			if (data->fmt.precision >= strlen)
				padding = data->fmt.width - strlen;
			else if (data->fmt.precision < strlen)
				padding = data->fmt.width - data->fmt.precision;
		}
		else
			padding = data->fmt.width - strlen;
	}
	if (padding < 0)
		padding = 0;
	return (padding);
}

static int	ft_putstr_precision(t_data *data, char *s)
{
	if (data->fmt.precision >= 0)
	{
		if (ft_putstr(s, data->fmt.precision, data) == -1)
			return (-1);
	}
	else
	{
		if (ft_putstr(s, ft_strlen(s), data) == -1)
			return (-1);
	}
	return (1);
}

//[-][width][.precision]
int	ft_print_str(t_data *data, char *s)
{
	int	padding;

	if (s == NULL)
		s = "(null)";
	padding = ft_str_spaces(data, s);
	if (data->fmt.left == 1)
	{
		if (ft_putstr_precision(data, s) == -1)
			return (-1);
		if (ft_putchar(' ', padding, data) == -1)
			return (-1);
	}
	else
	{
		if (data->fmt.zero == 1 && (ft_putchar('0', padding, data) == -1))
			return (-1);
		else if (data->fmt.zero == 0 && (ft_putchar(' ', padding, data) == -1))
			return (-1);
		if (ft_putstr_precision(data, s) == -1)
			return (-1);
	}
	return (1);
}
