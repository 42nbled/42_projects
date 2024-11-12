/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 02:23:03 by nbled             #+#    #+#             */
/*   Updated: 2022/09/04 02:23:05 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				value;
	unsigned int	index;
	struct s_pile	*next;
}					t_pile;

typedef struct s_start
{
	t_pile	*start_a;
	t_pile	*start_b;
}			t_start;

int		main(int argc, char **argv);
t_start	*ft_newstruct(void);
void	push_swap(t_start *start);
int		push_swap_condition(int argc, char **argv);
void	*push_swap_parsing(int argc, char **argv);

void	push_swap_sort_two(t_start *start);
void	push_swap_sort_three(t_start *start);
void	push_swap_sort_four(t_start *s);
void	push_swap_sort_five(t_start *s);
void	push_swap_sort_under_sixteen(t_start *start);
void	true_push_swap(t_start *start);
size_t	first_presort(t_start *start);

void	swap(char *index, t_start *start);
void	push(char *index, t_start *start);
void	rotate(char *index, t_start *start);
void	reverse_rotate(char *index, t_start *start);

int		ft_strlen(const char *s);
long	ft_atoi(char *str);
void	ft_putstr(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

t_pile	*ft_lstnew(int value, int index);
void	ft_lstadd_back(t_pile **pile, t_pile *n);
size_t	ft_lstsize(t_pile *pile);
t_pile	*ft_lstlast(t_pile *pile);
void	ft_lstclear(t_pile *start);

#endif
