/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_upper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:49:27 by iabasala          #+#    #+#             */
/*   Updated: 2024/11/13 15:20:29 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_upper(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789ABCDEF";
	if (n >= 16)
		i += ft_printhex_upper(n / 16);
	i += ft_putchar(str[n % 16]);
	return (i);
}
