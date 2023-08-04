/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define DICT_PATH "dicts/numbers.dict"

typedef struct s_dictline
{
	char	*nbr;
	char	*str;
}	t_dictline;

typedef struct s_parse_points
{
	int	nbr_start;
	int	nbr_end;
	int	str_start;
	int	str_end;
}	t_parse_points;

// ft_lib[1-3].c
void		ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_count_lines(char *str);
void		free_dict_array(t_dictline *dict);
void		print_dict_array(t_dictline *dict);
char		*ft_strndup(char *src, int n);
void		*ft_calloc(int count, int size);
void		*ft_realloc(void *ptr, int old_size, int new_size);
char		*ft_strcat(char *dest, char *src);
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);

// readfile.c
t_dictline	*parse_file(char *file_path);

// nbeditor[1-2].c
int			nbeditor(char *nb, t_dictline *dict, int is_french, char **result);
int			add_to_result(char **res, char *text);
int			add_if_in_dict(t_dictline *dict, int is_french,
				char **result, char *nb_copy);
int			add_multiples_of_thousand(char *nb_copy, int is_french,
				t_dictline *dict, char **result);
int			add_multiples_of_ten(char *nb_copy, t_dictline *dict,
				int is_french, char **result);

// check_arg.c
void		trimming_spaces(char	**str, int i, int index);
int			check_number(char **arg, int index);

// main.c
void		call_nbeditor(char *str, t_dictline *file_cnt);

// pingpong.c
void		pingpong(t_dictline *file_cnt);

#endif
