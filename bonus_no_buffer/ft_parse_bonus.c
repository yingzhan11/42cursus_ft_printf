/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:20:02 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/21 17:10:36 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_refresh_fmt(t_data *data)
{
	data->fmt.left = 0;
	data->fmt.plus = 0;
	data->fmt.space = 0;
	data->fmt.zero = 0;
	data->fmt.hash = 0;
	data->fmt.width = 0;
	data->fmt.precision = -1;
	data->fmt.is_signed = 0;
	data->fmt.is_negative = 0;
	data->fmt.is_upper = 0;
	data->fmt.nb_len = 0;
	data->fmt.pad_space = 0;
	data->fmt.pad_zero = 0;
}

static void	ft_parse_flag(t_data *data)
{
	char	flag;

	while (my_strchr(FLAGS, *data->s))
	{
		flag = *data->s;
		if (flag == '-')
			data->fmt.left = 1;
		else if (flag == '+')
			data->fmt.plus = 1;
		else if (flag == ' ')
			data->fmt.space = 1;
		else if (flag == '#')
			data->fmt.hash = 1;
		else if (flag == '0')
			data->fmt.zero = 1;
		data->s++;
	}
}

static void	ft_get_value(t_data *data, int *value)
{
	int	i;

	i = 0;
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		data->s++;
		return ;
	}
	while (my_strchr(NUMBERS, *data->s))
	{
		i = (i * 10) + (*data->s - '0');
		data->s++;
	}
	*value = i;
}

void	ft_parse_format(t_data *data)
{
	ft_refresh_fmt(data);
	while (!my_strchr(SPECIFIERS, *data->s) || !(data->s))
	{
		if (my_strchr(FLAGS, *data->s))
			ft_parse_flag(data);
		else if (my_strchr(NUMBERS, *data->s) || *data->s == '*')
			ft_get_value(data, &data->fmt.width);
		else if (*data->s == '.' && *(++data->s))
			ft_get_value(data, &data->fmt.precision);
	}
	data->fmt.specifier = *data->s;
	if (my_strchr("diu", data->fmt.specifier))
	{
		data->fmt.base = 10;
		if (data->fmt.specifier != 'u')
			data->fmt.is_signed = 1;
	}
	else if (my_strchr("xXp", data->fmt.specifier))
	{
		data->fmt.base = 16;
		if (data->fmt.specifier == 'X')
			data->fmt.is_upper = 1;
	}
}
