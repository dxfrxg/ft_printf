/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:53:48 by daxferab          #+#    #+#             */
/*   Updated: 2024/05/24 13:47:31 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(size_t num, char *hex_list)
{
	int	bytes;

	bytes = 0;
	if (num >= 16)
		bytes += ft_printhex(num / 16, hex_list);
	bytes += write(1, &hex_list[num % 16], 1);
	return (bytes);
}
