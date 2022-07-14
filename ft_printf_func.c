/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:14:21 by igondra-          #+#    #+#             */
/*   Updated: 2022/07/14 11:54:37 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		ft_putchar_fd(s[i++], fd);
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				long_n;

	num = 0;
	long_n = 1;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);   // ft_itoa(INT_MIN)
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
		long_n++;
	}
	else
		num = n;
	if (num > 9)
	{
		long_n = long_n + ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((char)(num % 10 + '0'), fd);
	return (long_n);
}

int	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	unsigned int	num;
	int				long_n;

	num = n;
	long_n = 1;
	if (num > 9)
	{
		long_n = long_n + ft_putnbr_unsigned_fd(num / 10, fd);
	}
	ft_putchar_fd((char)(num % 10 + '0'), fd);
	return (long_n);
}

int	ft_puthexa_fd(unsigned long int n, char c, int fd)
{
	int		long_n;

	long_n = 1;
	if (c == 'p' || c == 'x')
	{
		if (n >= 16)
			long_n = long_n + ft_puthexa_fd(n / 16, c, fd);
		ft_putchar_fd("0123456789abcdef"[n % 16], fd);
	}
	else if (c == 'X')
	{
		if (n >= 16)
			long_n = long_n + ft_puthexa_fd(n / 16, c, fd);
		ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
	}
	return (long_n);
}
