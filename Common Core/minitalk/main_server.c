/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:47:07 by nbled             #+#    #+#             */
/*   Updated: 2022/10/24 17:01:44 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_server.h"

t_struct	g_data;

char	*ft_charjoin(char *s1, char s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	size = 0;
	while (s1 && s1[size])
		size++;
	tab = malloc((size + 2));
	if (tab == NULL)
		return (NULL);
	while (s1 && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i++] = s2;
	tab[i] = '\0';
	free(s1);
	return (tab);
}

void	string_handler(int sig)
{
	static int	i = 0;

	g_data.c *= 2;
	if (sig == SIGUSR2)
		g_data.c++;
	i++;
	if (i == 8)
	{
		g_data.str = ft_charjoin(g_data.str, g_data.c);
		if (g_data.c == '\0')
		{
			ft_putstr(CYAN"client : "END);
			ft_putstr(g_data.str);
			ft_putchar('\n');
			free(g_data.str);
			g_data.str = NULL;
		}
		g_data.c = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	action;

	ft_putstr(YELLOW"+-------- ");
	ft_putstr(GREEN"MINI_TALK");
	ft_putstr(YELLOW" --------+\n");
	ft_putstr("|    The Server is ");
	ft_putstr(GREEN"OPEN");
	ft_putstr(YELLOW"     |\n|    The PID is : "GREEN);
	ft_putnbr(getpid());
	ft_putstr(YELLOW"    |\n");
	ft_putstr("+---------------------------+\n\n"END);
	action.sa_handler = string_handler;
	action.sa_flags = SA_SIGINFO;
	g_data.str = NULL;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
