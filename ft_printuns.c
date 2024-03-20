/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:50:08 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 02:57:09 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printuns(unsigned int num)
{
	char	digit;

	if (num < 10)
	{
		digit = num + '0';
		write(1, &digit, 1);
	}
	else
	{
		ft_printuns(num / 10);
		digit = num % 10 + '0';
		write(1, &digit, 1);
	}
}
