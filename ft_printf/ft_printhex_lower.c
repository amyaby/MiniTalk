/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex_lower.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:06:42 by iabasala          #+#    #+#             */
/*   Updated: 2024/11/09 21:51:31 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex_lower(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = "0123456789abcdef";
	if (n >= 16)
		i += ft_printhex_lower(n / 16);
	i += ft_putchar(str[n % 16]);
	return (i);
}
