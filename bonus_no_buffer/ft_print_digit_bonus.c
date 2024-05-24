/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:30:15 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/22 10:58:18 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_itoa_base(t_data *data, long nb)
{
	int	base;

	base = data->fmt.base;
	if (nb < 0)
	{
		nb = -nb;
		data->fmt.is_negative = 1;
	}
	if (nb >= base)
	{
		ft_itoa_base(data, nb / base);
		ft_itoa_base(data, nb % base);
	}
	else if (nb < base)
	{
		if (data->fmt.is_upper == 1)
			data->fmt.nb_str[data->fmt.nb_len++] = UP_HEX[nb];
		else
			data->fmt.nb_str[data->fmt.nb_len++] = LOW_HEX[nb];
		data->fmt.nb_str[data->fmt.nb_len] = '\0';
	}
}

int	ft_print_digit(t_data *data, long nb)
{
	if (nb == 0 && data->fmt.precision == 0)
		data->fmt.nb_str[data->fmt.nb_len] = '0';
	else
		ft_itoa_base(data, nb);
	ft_pad_zeros(data);
	ft_pad_spaces(data);
	if (data->fmt.left)
	{
		if (ft_putall(data) == -1)
			return (-1);
		if (ft_putchar(' ', data->fmt.pad_space, data) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar(' ', data->fmt.pad_space, data) == -1)
			return (-1);
		if (ft_putall(data) == -1)
			return (-1);
	}
	return (1);
}
