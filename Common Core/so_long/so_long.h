/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:52:41 by nbled             #+#    #+#             */
/*   Updated: 2022/11/16 16:52:42 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32;1m"
# define YELLOW  "\x1b[33;1m"
# define BLUE    "\x1b[34;1m"
# define MAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36;1m"
# define END    "\x1b[0m"

# include	"mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	void	*three;
	void	*ground;
	void	*ground_player_facing_up;
	void	*ground_player_facing_left;
	void	*ground_player_facing_down;
	void	*ground_player_facing_right;
	void	*ground_collectible;
	void	*ground_trophee;
	void	*grass;
	void	*grass_player_facing_up;
	void	*grass_player_facing_left;
	void	*grass_player_facing_down;
	void	*grass_player_facing_right;
	void	*grass_collectible;
	void	*grass_trophee;
	void	*flower;
	void	*flower_player_facing_up;
	void	*flower_player_facing_left;
	void	*flower_player_facing_down;
	void	*flower_player_facing_right;
	void	*flower_collectible;
	void	*flower_trophee;
	char	**map;
	char	dir;
	int		x_end;
	int		y_end;
	t_data	img;
}				t_vars;

void	init_img(t_vars *vars);
char	*read_map(char *path);
void	get_end_location(t_vars *vars);
void	print_map(t_vars *vars, char **tab);
void	print_player(t_vars *vars, char **tab, int x, int y);
int		key_hook(int keycode, t_vars *vars);
int		ft_close(t_vars *vars);
void	free_map(t_vars *vars);

int		is_valid(t_vars *vars);
int		is_rectangular(char **s);
int		is_surrounded(char **s);
int		has_enough(char **s, int W, int F);
int		map_content(char **s, int P, int C, int E);
int		map_composition(char **s, int i, int y);
int		is_path(char **s);

int		ft_count_words(const char *s, char c);
int		ft_str_len(char const *s, char c);
char	**ft_split(char const *s, char c);
void	ft_putchar(int c);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*i_want_to_break_free(char *str1, char *str2);
char	*get_next_line(int fd);

#endif
 