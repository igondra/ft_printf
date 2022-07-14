/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:47:26 by igondra-          #+#    #+#             */
/*   Updated: 2022/07/14 11:55:01 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	int		cnt;
	int		fd;
	int		str_len;
	va_list	arg;  //Defino la lista variable, que son los ... de los argumentos de la función ft_print
	cnt = 0;
	fd = 1; // Para imprimir en pantalla, fd = 1
	str_len = 0;
	va_start(arg, str); // Inicio la variable arg (puntero) justo después de la variable const_str
	while (str[cnt] != '\0')
	{
		if (str[cnt] == '%') // Si sale el porcentaje, tenemos condición especial
		{
			cnt++;
			str_len = str_len + ft_printf_cond(arg, str[cnt], fd);
		}
		else
		{ // Si no sale porcentaje, simplemente imprimimos el carácter de la cadena const_str
			ft_putchar_fd(str[cnt], 1);
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

/* int	main(void)
{
	int	long_ft_printf;
	int	long_printf;

	long_ft_printf = 0;
	long_printf = 0;
 	ft_printf("Kaixo letra %c  eta esaldia %s \n", 'D', "Kaixo berriro");
	ft_printf("Kaixo letra segida: %c, %c, %c, %c, %c \n", 'K', 'a', 'i', 'x', 'o');
	ft_printf("Pointer bat: %p \n", "Hello");
	ft_printf("Zenbaki hamartarra (decimal): %d \n", 1569);
	ft_printf("Zenbaki osoa: %i \n", 56988);
	ft_printf("Zenbaki hamartarra (decimal) zeinu barik: %u \n", 3147483648);
	ft_printf("Zenbaki hamaseitarra minuskulan: %x \n", 16);
	ft_printf("Zenbaki hamaseitarra maiuskulan: %X \n", 15);
	ft_printf("Ehunekoaren sinboloa: %% \n \n");
	ft_printf("Popurri \n");
	ft_printf("Letra %c String %s Pointer %p Decimal %d Entero %i Unsigned %u hexa %x HEXA %X %% \n", 'T', "Kaixoo", "Agur", -134, 897, 4553, 15, 15);
	printf("Letra %c String %s Pointer %p Decimal %d Entero %i Unsigned %u hexa %x HEXA %X %% \n \n", 'T', "Kaixoo", "Agur", -134, 897, 4553, 15, 15);
	long_ft_printf = ft_printf("Hola %s %i Agur \n", "mundo", 1540);
	long_printf = printf("Hola %s %i Agur \n", "mundo", 1540);
	ft_printf("Long ft_printf = %d \nLong printf = %d \n", long_ft_printf, long_printf);
 	long_ft_printf = ft_printf("Hola %i\n", 1540);
	long_printf = printf("Hola %i\n", 1540);
	ft_printf("Long ft_printf = %d \nLong printf = %d \n", long_ft_printf, long_printf);
	return (0);
} */

// %c para imprimir un solo carácter.
// %s para imprimir una string (como se define por convención en C).
// %p el puntero void * dado como argumento se imprimirá en hexadecimal.
// %d para imprimir un número decimal (de base 10).
// %i para imprimir un entero en base 10.
// %u para imprimir un número decimal (de base 10) sin signo.
// %x para imprimir un número hexadecimal (de base 16), en minúscula.
// %X para imprimir un número hexadecimal (de base 16), en mayúscula.
// %% para imprimir el signo del porcentaje.
