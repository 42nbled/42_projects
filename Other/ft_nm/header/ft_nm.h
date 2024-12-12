#ifndef FT_NM_H
# define FT_NM_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "elf.h"

typedef struct s_name_table {
	char	*name;
	char	value[17];
	char	type;
	int		i_value;
	int		stt_type;
} t_name_table;

struct s_pair {
	t_Elf64_Sym	*symtable;
	char		*strtable;
};

typedef struct s_lst {
	struct s_lst	*next;
	t_name_table	*data;
} t_lst;

typedef struct s_files {
	struct s_files	*next;
	char			*name;
} t_files;

typedef struct s_flags {
	unsigned int	a : 1;
	unsigned int	g : 1;
	unsigned int	u : 1;
	unsigned int	r : 1;
	unsigned int	p : 1;
} t_flags;

// get_symbol_type.c
char get_symbol_type(char *secname, int bind, int type, unsigned long addr, short st_shndx);

// lst.c
t_lst *lst_last(t_lst *node);
int lst_append(t_lst *root, t_name_table *table);
void lst_clear(t_lst *root);
int lst_size(t_lst *node);
void ft_swap(t_lst **a, t_lst **b);
void ft_lst_swap(t_lst **header, t_lst *a, t_lst *b);
void ft_lst_sort(t_lst **begin_list, int (*cmp)());

// parse_table_32b.c
int run_32(int fd, t_fileinfo32 fileh, t_lst *root);

// parse_table_64b.c
int run_64(int fd, t_fileinfo64 fileh, t_lst *root);

// print_nm.c
void print_nm32(t_lst name_tables, t_flags flags, char *executable_name);
void print_nm64(t_lst name_tables, t_flags flags, char *executable_name);

// sort.c
int diff_str(t_lst *a, t_lst *b);

// sort.c
int reverse_diff_str(t_lst *a, t_lst *b);

#endif
