/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:14:21 by igondra-          #+#    #+#             */
/*   Updated: 2022/07/12 12:20:34 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	num = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = -n;
	}
	else
		num = n;
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((char)(num % 10 + '0'), fd);
}

void	ft_puthexa_fd(unsigned int n, int capital_letter, int fd)
{
	char	*hexa;
	int		counter;

	if (capital_letter == 1)
		hexa = "0123456789ABCDEF";
	else
		hexa = "0123456789abcdef";
	while (n > 0)
	{
		counter = n % 16;
		ft_putchar_fd(hexa[counter], fd);
		n = n / 16;
	}
}

/* int	main(void)
{
	printf("Chequeo de la funcion ft_puthexa_fd\n");
	printf("Numero en hexa = \n");
	ft_puthexa_fd(4805245, 1, 1);
	printf("\n");
	printf("Numero en hexa = \n");
	ft_puthexa_fd(6553784, 1, 1);
	return (0);
} */
