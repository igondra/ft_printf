/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:47:26 by igondra-          #+#    #+#             */
/*   Updated: 2022/10/06 18:18:03 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		cnt;
	int		fd;
	int		str_len;
	va_list	arg;

	cnt = 0;
	fd = 1;
	str_len = 0;
	va_start(arg, str);
	while (str[cnt] != '\0')
	{
		if (str[cnt] == '%')
		{
			cnt++;
			str_len = str_len + ft_printf_cond(arg, str[cnt], fd);
		}
		else
		{
			ft_putchar_fd(str[cnt], fd);
			str_len++;
		}
		cnt++;
	}
	va_end(arg);
	return (str_len);
}

int	ft_printf_cond(va_list arg, char c, int fd)
{
	int	str_len_sub;

	str_len_sub = 0;
	if (c == 'c')
		str_len_sub = ft_putchar_fd(va_arg(arg, int), fd);
	else if (c == 's')
		str_len_sub = ft_putstr_fd(va_arg(arg, char *), fd);
	else if (c == 'p')
	{
		str_len_sub = ft_putstr_fd("0x", fd) + \
			ft_puthexa_fd(va_arg(arg, unsigned long int), c, fd);
	}
	else if (c == 'd' || c == 'i')
		str_len_sub = ft_putnbr_fd(va_arg(arg, int), fd);
	else if (c == 'u')
		str_len_sub = ft_putnbr_unsigned_fd(va_arg(arg, unsigned long int), fd);
	else if (c == 'x')
		str_len_sub = ft_puthexa_fd(va_arg(arg, unsigned int), c, fd);
	else if (c == 'X')
		str_len_sub = ft_puthexa_fd(va_arg(arg, unsigned int), c, fd);
	else if (c == '%')
		str_len_sub = ft_putchar_fd('%', fd);
	return (str_len_sub);
}
