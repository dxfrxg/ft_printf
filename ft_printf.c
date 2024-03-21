/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:03 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/21 17:39:05 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	which_flag(char flag, va_list args)
{
	int	bytes;

	bytes = 0;
	if (flag == 'c')
		bytes += ft_printchar(va_arg(args, int));
	else if (flag == 's')
		bytes += ft_printstr(va_arg(args, char *));
	else if (flag == 'p')
		bytes += ft_printptr(va_arg(args, int));
	else if (flag == 'd')
		bytes += ft_printdec(va_arg(args, double));
	else if (flag == 'i')
		bytes += ft_printnbr(va_arg(args, int));
	else if (flag == 'u')
		bytes += ft_printuns(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		bytes += ft_printhex(va_arg(args, int), flag);
	else if (flag == '%')
	{
		write(1, "%", 1);
		bytes++;
	}
	return (bytes);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += which_flag((char)*str, args);
		}
		else
		{
			write(1, str, 1);
			bytes++;
		}
		str++;
	}
	va_end(args);
	return (bytes);
}

/*int	main(void)
{
	ft_printf(" %d ", 0);
	printf("\n");
	printf("%f, %f, %f", 0.00, 23.5, 32.68987654654);
}*/
