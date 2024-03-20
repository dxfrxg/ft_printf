/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:03 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 02:39:47 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	which_flag(char flag, va_list args)
{
	if (flag == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (flag == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (flag == 'p')
		ft_printptr(va_arg(args, int));
	else if (flag == 'd')
		ft_printdec(va_arg(args, double));
	else if (flag == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (flag == 'u')
		ft_printuns(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		ft_printhex(va_arg(args, int), flag);
	else if (flag == '%')
		write(1, "%", 1);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			which_flag(str[i + 1], args);
			i++;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}
/*int	main(void)
{
	void	*str = "holas";

	ft_printf("ptr: %p", str);
	printf("\n");
	printf("ptr: %p", str);
}*/
