/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daxferab <daxferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:57:16 by daxferab          #+#    #+#             */
/*   Updated: 2024/03/20 02:38:15 by daxferab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "libft/libft.h"

int		ft_printf(char const *str, ...);
void	ft_printptr(unsigned long long ptr);
void	ft_printdec(double num);
void	ft_printhex(int num, char flag);
void	ft_printuns(unsigned int num);

#endif
