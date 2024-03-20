/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:03 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 18:06:02 by daxferab         ###   ########.fr       */
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
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			bytes += which_flag(str[i + 1], args);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			bytes++;
		}
		i++;
	}
	va_end(args);
	return (bytes);
}
/*int	main(void)
{
	ft_printf("NULL %s NULL", NULL);
	printf("\n");
	printf("NULL %s NULL", NULL);
}*/
