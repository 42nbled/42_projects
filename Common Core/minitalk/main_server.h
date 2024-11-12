/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:47:46 by nbled             #+#    #+#             */
/*   Updated: 2022/10/14 14:47:48 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_SERVER_H
# define MAIN_SERVER_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32;1m"
# define YELLOW  "\x1b[33;1m"
# define BLUE    "\x1b[34;1m"
# define MAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36;1m"
# define END    "\x1b[0m"

typedef struct s_struct
{
	char	c;
	char	*str;
	pid_t	client;
}				t_struct;

void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);

#endif