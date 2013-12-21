/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 15:44:53 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/21 22:26:59 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_if_s(t_data *data)
{
	data->str_cpy = ft_strdup(va_arg(data->ap, char *));
	ft_putstr_exep(data, data->str_cpy);
}

void		ft_if_d(t_data *data)
{
		data->str_nb = ft_strdup(ft_itoa(va_arg(data->ap, int)));
		ft_putstr_exep(data, data->str_nb);
}

void		ft_if(char *str, t_data *data)
{
	if (str[data->i] == '%')
		{
			data->i++;
			if (str[data->i] == 'c' )
				ft_putchar_exep(data, va_arg(data->ap, int));
			if (str[data->i] == 's')
				ft_if_s(data);
			if (str[data->i] == 'd')
				ft_if_d(data);
		}
}

void		ft_putchar_exep(t_data *d, char c)
{
	if (c != '%')
	{
		ft_putchar(c);
		d->count++;
	}
}

void		ft_putstr_exep(t_data *d, char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		d->count++;
		i++;
	}
}

int		ft_printf(char *str, ...)
{
	t_data		d;

	va_start(d.ap, str);
	d.i = 0;
	d.count = 0;
	while (str[d.i] != 0)
	{
		ft_putchar_exep(&d, str[d.i]);
		ft_if(str, &d);
		d.i++;
	}
	ft_putchar('\n');
	va_end(d.ap);
	ft_putnbr(d.count);
	return (d.count);
}
