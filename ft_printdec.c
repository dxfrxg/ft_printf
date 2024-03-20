/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:16:12 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 12:18:25 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printdec_rec(double num, int prec)
{
	unsigned int	fractional_part;

	if (prec == 0)
		return ;
	fractional_part = (unsigned int)(num * 10);
	ft_printuns(fractional_part);
	ft_printdec_rec((num * 10) - fractional_part, prec - 1);
}

void	ft_printdec(double num)
{
	unsigned int	integer_part;

	if (num == 0)
	{
		write(1, "0.", 2);
		ft_printdec_rec(0, 6);
	}
	else
	{
		if (num < 0)
		{
			write(1, "-", 1);
			num *= -1;
		}
		integer_part = (unsigned int)num;
		ft_printuns(integer_part);
		write(1, ".", 1);
		ft_printdec_rec(num - integer_part, 6);
	}
}
