/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:53:48 by daxferab          #+#    #+#             */
/*   Updated: 2024/04/06 05:57:02 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t num, char *hex_list)
{
	int	bytes;

	bytes = 0;
	if (num >= 16)
		bytes += ft_puthex(num / 16, hex_list);
	bytes += write(1, &hex_list[num % 16], 1);
	return (bytes);
}

int	ft_printhex(size_t num, char flag)
{
	char	*hex_min;
	char	*hex_max;

	hex_min = "0123456789abcdef";
	hex_max = "0123456789ABCDEF";
	if (flag == 'x')
		return (ft_puthex(num, hex_min));
	else
		return (ft_puthex(num, hex_max));
}
