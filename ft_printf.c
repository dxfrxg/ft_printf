/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:03 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/15 18:51:22 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!p)
		return 0;
	while (*str)
	{
		*p = *str;
		p++;
		str++;
	}
	write(1, p, ft_strlen(p));
	return 0;
}
int	main(void)
{
	ft_printf("Hola que tal");
	printf("\n");
	printf("Hola que tal");
}
