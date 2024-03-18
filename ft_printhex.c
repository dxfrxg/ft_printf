/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 01:53:48 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/18 02:30:24 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(int num, char flag)
{
	if (num >= 16)
	{
		ft_printhex(num / 16, flag);
		ft_printhex(num % 16, flag);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (flag == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (flag == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}
