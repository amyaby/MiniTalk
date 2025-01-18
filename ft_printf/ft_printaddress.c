/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:29:28 by iabasala          #+#    #+#             */
/*   Updated: 2024/11/09 21:27:05 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(unsigned long n)
{
	int		i;
	char	*str;

	str = "0123456789abcdef";
	i = 0;
	if (n < 16)
		i += ft_putchar(str[n]);
	else
	{
		i += ft_printaddress(n / 16);
		i += ft_putchar(str[n % 16]);
	}
	return (i);
}
