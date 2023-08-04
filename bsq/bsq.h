/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define HELP_CODE 1

typedef struct s_sqrt
{
	int	x;
	int	y;
	int	size;
}				t_sqrt;

typedef struct t_map
{
	int		nb_l;
	int		nb_c;
	char	empty;
	char	obstacle;
	char	full;
	int		**map;
	t_sqrt	sq;
}				t_map;

typedef struct s_arg
{
	int		x;
	int		y;
	int		prop;
	int		pos;
	int		seed;
	int		used_entry;
	char	**files;
}				t_arg;

// utilities.c
int		ft_line_len(char *str);
int		ft_atoin(char *str, int size);
char	*ft_strcat(char *dest, char *src);
t_map	*dual_free(void *ptr1, void *ptr2);

// utilities2.c
void	warn_bad_flag(char *avi);
int		get_file_len(char *file_path);

// ft_lib.c
int		ft_atoi(char *str);
int		ft_3min(int a, int b, int c);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

// solver.c
void	solve_map(t_map *print);

// tab_things.c
int		**tab_gen(int tab[10][10]);
void	print_tab(int just_pos, t_map print);
void	free_tab(int **tab, int nb_l);

// gen_tab.c
int		**gen_rand_tab(int x, int y, unsigned int prop, unsigned int seed);

// parse.c
t_arg	*parsearg(int ac, char **av);

// check_map.c
int		check_consistency(t_map *map, char *buffer);
int		check_line(t_map *map, char *buffer);
int		check_min_line(char *buffer);
int		check_first_line(t_map *map);

// memory_manager.h
t_map	*ft_struct_malloc(t_map *map);
t_arg	*free_and_ret(t_arg *arg);
void	*ft_calloc(int count, int size);
void	ft_map_malloc(t_map *map);
void	*ft_realloc(void *ptr, unsigned long long old_size,
			unsigned long long new_size);

// reader.c
t_map	*read_map(char *filepath);

// sdtinread.c
char	*read_stdin(void);

#endif
