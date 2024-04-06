/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:03 by daxferab          #+#    #+#             */
/*   Updated: 2024/04/06 05:55:52 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	which_flag(char flag, va_list args)
{
	if (flag == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (flag == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (flag == 'p')
		return (ft_printptr(va_arg(args, size_t)));
	else if (flag == 'i' || flag == 'd')
		return (ft_printnbr(va_arg(args, int)));
	else if (flag == 'u')
		return (ft_printuns(va_arg(args, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return (ft_printhex(va_arg(args, size_t), flag));
	else if (flag == '%')
		return (write(1, "%", 1));
	return (0);
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
			bytes += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (bytes);
}

/*int	main(void)
{
	char	*str;

	str = "hola";
	ft_printf("Copia:\nHex: %x", __LONG_MAX__);
	printf("\n\n");
	printf("Original:\nHex: %x", __LONG_MAX__);
}*/