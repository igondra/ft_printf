/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igondra- <igondra-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 09:47:26 by igondra-          #+#    #+#             */
/*   Updated: 2022/07/12 12:34:40 by igondra-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

int	ft_printf(char const *const_str, ...)
{
	int		counter;
	va_list	arguments; // Defino la lista variable, que son los ... de los argumentos de la función ft_print
	counter = 0;
	va_start(arguments, const_str); // Inicio la variable arguments (puntero) justo después de la variable const_str
	while (const_str[counter] != '\0')
	{
		if (const_str[counter] == '%') // Si sale el porcentaje, tenemos condición especial
		{
			counter++;
			ft_printf_conversion(arguments, const_str[counter++]);
		}
		else // Si no sale porcentaje, simplemente imprimimos el carácter de la cadena const_str
			ft_putchar_fd(const_str[counter], 1);
		counter++;
	}
	va_end(arguments);
	return (0);
}

void	ft_printf_conversion(va_list arguments, char c)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arguments, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(arguments, char *), 1);
	//else if (c == 'p')
	//	ft_puthexa_fd(va_arg(arguments, void *), 0, 1);
	//else if (c == 'd')
	//	ft_putnbr(); // Tiene que ser para número decimal
	else if (c == 'i')
		ft_putnbr_fd(va_arg(arguments, int), 1);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(arguments, unsigned int), 1);
	else if (c == 'x')
		ft_puthexa_fd(va_arg(arguments, unsigned int), 0, 1);
	else if (c == 'X')
		ft_puthexa_fd(va_arg(arguments, unsigned int), 1, 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
}

int	main(void)
{
	ft_printf("Kaixo letra %c  eta esaldia %s \n", 'D', "Kaixo berriro");
	ft_printf("Kaixo letra segida: %c, %c, %c, %c, %c \n", 'a', 'b', 'c', 'd', 'e');
	return (0);
}

// %c para imprimir un solo carácter.
// %s para imprimir una string (como se define por convención en C).
// %p el puntero void * dado como argumento se imprimirá en hexadecimal.
// %d para imprimir un número decimal (de base 10).
// %i para imprimir un entero en base 10.
// %u para imprimir un número decimal (de base 10) sin signo.
// %x para imprimir un número hexadecimal (de base 16), en minúscula.
// %X para imprimir un número hexadecimal (de base 16), en mayúscula.
// % % para imprimir el signo del porcentaje.
