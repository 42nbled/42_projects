/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 00:46:33 by nbled             #+#    #+#             */
/*   Updated: 2022/10/16 00:46:36 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	s;

	i = 0;
	result = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s -= 2;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result *= 10;
		result += (nptr[i] -48);
		i++;
	}
	return (result * s);
}

void	send_char(int pid, char c)
{
	int	i;

	i = 128;
	while (i != 0)
	{
		if (c >= i)
		{
			c -= i;
			kill(pid, SIGUSR2);
		}
		else
			kill(pid, SIGUSR1);
		usleep(1000);
		if (i != 1)
			i /= 2;
		else
			i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
			return (0);
		while (argv[2][i])
			send_char(pid, argv[2][i++]);
		send_char(pid, '\0');
	}
	usleep(1000);
	return (0);
}
