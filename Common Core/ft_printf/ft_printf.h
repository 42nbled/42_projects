/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 20:28:30 by nbled             #+#    #+#             */
/*   Updated: 2022/07/14 02:39:10 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(int c, int j);
int	ft_putstr(char *s, int j);
int	ft_putptr(unsigned long long nb, char *base, int j);
int	ft_putnbr(int nb, int j);
int	ft_putunsigned(unsigned int nb, int j);
int	ft_puthexa(unsigned int nb, char *base, int j);
int	ft_printf(const char *format, ...);

#endif
