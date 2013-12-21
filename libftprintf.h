/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/21 18:28:53 by gpetrov           #+#    #+#             */
/*   Updated: 2013/12/21 23:31:20 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_data
{
	va_list			ap;
	int				i;
	char			*str_cpy;
	char			*str_nb;
	int				count;
}					t_data;

void	ft_putchar(char c);
void	ft_putstr(char const *str);
char	*ft_strcpy(char *s1, char *s2);
void	ft_putnbr(int n);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
char	*ft_strdup(char *src);
void	ft_if(char *str, t_data *data);
void	ft_if_s(t_data *data);
void	ft_if_d(t_data *data);
void	ft_if(char *str, t_data *data);
void	ft_putstr_exep(t_data *d, char *str);
void	ft_putchar_exep(t_data *d, char c);
char	*ft_itoa(int n);
int		ft_printf(char *str, ...);

#endif
