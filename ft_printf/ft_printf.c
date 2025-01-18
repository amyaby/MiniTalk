/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 15:38:01 by im_ane            #+#    #+#             */
/*   Updated: 2024/11/14 18:16:19 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cases(const char *format, va_list args)
{
	int	print_char;

	print_char = 0;
	if (*format == '%')
		print_char += ft_putchar('%');
	else if (*format == 'c')
		print_char += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		print_char += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
	{
		print_char += ft_putstr("0x");
		print_char += ft_printaddress(va_arg(args, unsigned long));
	}
	else if (*format == 'd' || *format == 'i')
		print_char += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		print_char += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		print_char += ft_printhex_lower(va_arg(args, unsigned int));
	else if (*format == 'X')
		print_char += ft_printhex_upper(va_arg(args, unsigned int));
	return (print_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_char;

	print_char = 0;
	va_start(args, format);
	if (!format || write(1, 0, 0) == -1)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			if (*format)
				print_char += ft_cases(format, args);
		}
		else
			print_char += write(1, format, 1);
		if (print_char == -1)
			return (-1);
		format++;
	}
	va_end(args);
	return (print_char);
}
