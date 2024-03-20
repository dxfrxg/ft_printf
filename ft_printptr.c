/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 02:14:27 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 17:59:02 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(uintptr_t num, int *bytes)
{
	if (num >= 16)
	{
		ft_putptr(num / 16, bytes);
		ft_putptr(num % 16, bytes);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
		(*bytes)++;
	}
	return (*bytes);
}

int	ft_printptr(unsigned long long ptr)
{
	int bytes;
	write(1, "0x", 2);

	bytes = 0;
	ft_putptr(ptr, &bytes);
	return (bytes);
}
