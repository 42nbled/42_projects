/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:10:34 by nbled             #+#    #+#             */
/*   Updated: 2022/07/11 20:35:03 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int	ft_putnbr(int nb, int j)
//{
//	if (nb == -2147483648)
//	{
//		write(1, "-2147483648", 11);
//		j += 11;
//	}
//	else if (nb >= 0 && nb < 10)
//	{
//		j = ft_putchar(nb + 48, j);
//	}
//	else if (nb < 0)
//	{
//		j = ft_putchar('-', j);
//		j = ft_putnbr(nb *(-1), j);
//	}
//	else
//	{
//		j = ft_putnbr(nb / 10, j);
//		j = ft_putnbr(nb % 10, j);
//	}
//	return (j);
//}


int	ft_putnbr2(int nb, int j)
{
	int	tabl[11];
	int	count;
	int	a;

	count = 0;
	while (nb > 0)
	{
		a = nb % 10;
		tabl[count] = a;
		count++;
		nb = nb / 10;
	}
	count--;
	while (count >= 0)
	{
		a = tabl[count];
		j = ft_putchar(a + '0', j);
		count--;
	}	
	return (j);
}

int	ft_putnbr(int nb, int j)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		j+= 11;
	}
	else if (nb == 0)
		j = ft_putchar(48, j);
	else if (nb < 0)
	{
		nb = nb * -1;
		j = ft_putchar(45, j);
		j = ft_putnbr(nb, j);
	}
	else
		j = ft_putnbr2(nb, j);
	return (j);
}
