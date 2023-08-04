/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

// platthings.c
void	init_plat(int **plat, int plat_size);
void	print_plat(int **plat, int plat_size, int new_line);
void	free_plat(int **plat, int plat_size);

// countvisible.c
int		count_visible(int **plat, int vue, int pos, int plat_size);

// utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		count_words(char *str);
int		ft_atoi_lite(char *str);

// userparse.c
int		generate_tab(char *str, int **user_tab);
void	print_nb_sol(int nb, int does_print);

// isvalid.c
int		is_valid_plat(int **plat, int plat_size);
int		is_user_solution(int **plat, int *user_tab, int plat_size);
int		is_matching_vue(int **plat, int *user_tab, int y, int plat_size);

// ft_putnbr.c
void	ft_putnbr(int nb);

#endif
