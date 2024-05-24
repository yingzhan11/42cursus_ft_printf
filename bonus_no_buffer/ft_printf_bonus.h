/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhan <yzhan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:13:45 by yzhan             #+#    #+#             */
/*   Updated: 2024/05/22 11:01:27 by yzhan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdint.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-+ 0#"
# define NUMBERS "0123456789"
# define LOW_HEX "0123456789abcdef"
# define UP_HEX "0123456789ABCDEF"

//tmp data for each %, need to be refresh
typedef struct s_format
{
	//flags
	int			left;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	//width & precision
	int			width;
	int			precision;
	//specifier "cspdiuxX%"
	char		specifier;
	//signed
	int			is_signed;
	int			is_negative;
	//base
	int			base;
	//case
	int			is_upper;
	//nb
	char		nb_str[64];
	int			nb_len;
	int			pad_space;
	int			pad_zero;
}	t_format;

//const data
typedef struct s_data
{
	const char	*s;
	int			len;
	va_list		ap;
	t_format	fmt;
}	t_data;

//main
int		ft_printf(const char *format, ...);
void	ft_parse_format(t_data *data);
int		ft_print_char(t_data *data, int c);
int		ft_print_str(t_data *data, char *s);
int		ft_print_digit(t_data *data, long nb);
int		ft_print_pointer(t_data *data, void *ptr);

//utilities
int		ft_putchar(int c, int n, t_data *data);
int		my_strchr(const char *s, char c);
int		ft_strlen(const char *s);
int		ft_putstr(char *s, int precision, t_data *data);

//nb utilities
void	ft_pad_zeros(t_data *data);
void	ft_pad_spaces(t_data *data);
int		ft_putsign(t_data *data);
int		ft_putall(t_data *data);

#endif
