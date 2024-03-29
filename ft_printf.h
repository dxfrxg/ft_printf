/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:16 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/22 19:09:17 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int	ft_printf(char const *str, ...);
int	ft_printchar(int c);
int	ft_printnbr(int num);
int	ft_printstr(char *c);
int	ft_printptr(unsigned long long ptr);
int	ft_printhex(int num, char flag);
int	ft_printuns(unsigned int num);

#endif
