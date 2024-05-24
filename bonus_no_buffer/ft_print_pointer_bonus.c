/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:33:33 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/22 11:01:05 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	ft_convert_pointer(t_data *data, uintptr_t nb)
{
	if (nb >= 16)
	{
		ft_convert_pointer(data, nb / 16);
		data->fmt.nb_str[data->fmt.nb_len++] = LOW_HEX[nb % 16];
	}
	else if (nb < 16)
	{
		data->fmt.nb_str[data->fmt.nb_len++] = LOW_HEX[nb % 16];
	}
}

int	ft_print_pointer(t_data *data, void *ptr)
{
	ft_convert_pointer(data, (uintptr_t)ptr);
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
