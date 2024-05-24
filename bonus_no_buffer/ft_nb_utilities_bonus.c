/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_utilities_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:22:43 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/22 10:44:11 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_pad_zeros(t_data *data)
{
	if (data->fmt.precision >= 0)
	{
		if (data->fmt.precision >= data->fmt.nb_len)
			data->fmt.pad_zero = data->fmt.precision - data->fmt.nb_len;
		return ;
	}
	if (data->fmt.zero)
	{
		if (data->fmt.left)
			return ;
		if (data->fmt.width > data->fmt.nb_len)
			data->fmt.pad_zero = data->fmt.width - data->fmt.nb_len;
		if (data->fmt.specifier == 'u')
			return ;
		else if ((my_strchr("xX", data->fmt.specifier) && data->fmt.hash
				&& data->fmt.nb_str[0] != '0') || data->fmt.specifier == 'p')
			data->fmt.pad_zero -= 2;
		else if (data->fmt.is_negative || (!data->fmt.is_negative
				&& (data->fmt.plus || data->fmt.space)))
			data->fmt.pad_zero--;
		if (data->fmt.pad_zero < 0)
			data->fmt.pad_zero = 0;
	}
}

void	ft_pad_spaces(t_data *data)
{
	int		width;
	char	specifier;

	width = data->fmt.width;
	specifier = data->fmt.specifier;
	data->fmt.pad_space = width - data->fmt.pad_zero - data->fmt.nb_len;
	if (my_strchr("uxXp", specifier))
	{
		if ((my_strchr("xX", specifier) && data->fmt.hash
				&& data->fmt.nb_str[0] != '0') || specifier == 'p')
		{
			data->fmt.pad_space -= 2;
		}
	}
	else if (data->fmt.is_negative || (!data->fmt.is_negative
			&& (data->fmt.plus || data->fmt.space)))
	{
		data->fmt.pad_space--;
	}
	if (data->fmt.pad_space < 0)
		data->fmt.pad_space = 0;
}

int	ft_putsign(t_data *data)
{
	if ((my_strchr("xX", data->fmt.specifier) && data->fmt.hash
			&& data->fmt.nb_str[0] != '0') || data->fmt.specifier == 'p')
	{
		if (data->fmt.is_upper && (ft_putstr("0X", 2, data) == -1))
			return (-1);
		else if (!data->fmt.is_upper && (ft_putstr("0x", 2, data) == -1))
			return (-1);
	}
	else if (data->fmt.is_signed)
	{
		if (data->fmt.is_negative && (ft_putchar('-', 1, data) == -1))
			return (-1);
		else if (!data->fmt.is_negative)
		{
			if (data->fmt.plus && (ft_putchar('+', 1, data) == -1))
				return (-1);
			else if (!data->fmt.plus && data->fmt.space)
			{
				if (ft_putchar(' ', 1, data) == -1)
					return (-1);
			}
		}
	}
	return (1);
}

int	ft_putall(t_data *data)
{
	if (ft_putsign(data) == -1)
		return (-1);
	if (ft_putchar('0', data->fmt.pad_zero, data) == -1)
		return (-1);
	if (ft_putstr(data->fmt.nb_str, data->fmt.nb_len, data) == -1)
		return (-1);
	return (1);
}
