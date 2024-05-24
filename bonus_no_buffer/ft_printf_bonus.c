/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:14:09 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/21 17:10:42 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	ft_check_specifier(t_data *data)
{
	char	specifier;

	specifier = data->fmt.specifier;
	if (specifier == 'c')
		ft_print_char(data, va_arg(data->ap, int));
	else if (specifier == 's')
		ft_print_str(data, va_arg(data->ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		ft_print_digit(data, (long)va_arg(data->ap, int));
	else if (my_strchr("uxX", specifier))
		ft_print_digit(data, (long)va_arg(data->ap, unsigned int));
	else if (specifier == 'p')
		ft_print_pointer(data, va_arg(data->ap, void *));
	else if (specifier == '%')
		ft_print_char(data, '%');
	return (data->len);
}

static int	ft_check_format(t_data *data)
{
	while (*data->s)
	{
		if (*data->s == '%')
		{
			if (!*(++data->s))
				return (data->len);
			ft_parse_format(data);
			if (ft_check_specifier(data) == -1)
				return (-1);
		}
		else
		{
			if (ft_putchar(*data->s, 1, data) == -1)
				return (-1);
		}
		data->s++;
	}
	return (data->len);
}

int	ft_printf(const char *format, ...)
{
	t_data	data;

	va_start(data.ap, format);
	data.s = format;
	data.len = 0;
	ft_check_format(&data);
	va_end(data.ap);
	return (data.len);
}
