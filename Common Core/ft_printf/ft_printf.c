/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:27:52 by nbled             #+#    #+#             */
/*   Updated: 2022/07/11 20:40:59 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_index(char c, va_list *args, int j)
{
	if (c == 'c')
		j = ft_putchar(va_arg(*args, int), j);
	if (c == 's')
		j = ft_putstr(va_arg(*args, char *), j);
	if (c == 'p')
		j = ft_putptr(va_arg(*args, unsigned long long), "0123456789abcdef", j);
	if (c == 'd' || c == 'i')
		j = ft_putnbr(va_arg(*args, int), j);
	if (c == 'u')
		j = ft_putunsigned(va_arg(*args, unsigned long), j);
	if (c == 'x')
		j = ft_puthexa(va_arg(*args, unsigned), "0123456789abcdef", j);
	if (c == 'X')
		j = ft_puthexa(va_arg(*args, unsigned), "0123456789ABCDEF", j);
	if (c == '%')
		j = ft_putchar('%', j);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			j = ft_index(format[++i], &args, j);
		else
			j = ft_putchar(format[i], j);
		i++;
	}
	va_end(args);
	return (j);
}
