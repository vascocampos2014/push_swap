/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaires-m <vaires-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:07:39 by vaires-m          #+#    #+#             */
/*   Updated: 2025/04/08 13:32:43 by vaires-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

int	check_letter(va_list args, const char letter);
int	ft_printf(const char *placeholders, ...);
int	ft_putnbr(long int nbr);
int	ft_putunsigned(unsigned int nbr);
int	ft_printhex(unsigned int n, const char letter);
int	ft_printstr(char *str);
int	ft_print_ptr(uintptr_t ptr);

#endif