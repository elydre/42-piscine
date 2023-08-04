/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

#define PRINT_ONE	0
#define PRINT_ALL	1
#define PRINT_VALID	2

int	full_plat_run(int **plat, int *user_tab, int plat_size)
{
	int	valid;

	valid = is_valid_plat(plat, plat_size);
	if (valid)
	{
		if (user_tab[-1] == PRINT_ALL)
			print_plat(plat, plat_size, 1);
		if (is_user_solution(plat, user_tab, plat_size))
		{
			if (user_tab[-1] != PRINT_ALL)
				print_plat(plat, plat_size, user_tab[-1] != PRINT_ONE);
		}
		else
			valid = 0;
	}
	plat[plat_size - 1][plat_size - 1] = 0;
	return (valid);
}

int	progress_plat(int **plat, int x, int y, int *user_tab)
{
	int	sol_count;
	int	i;

	i = 0;
	sol_count = 0;
	while (i < user_tab[-2])
	{
		plat[x][y] = ++i;
		if (!is_valid_plat(plat, user_tab[-2]))
			continue ;
		if (x == user_tab[-2] - 1 && y == user_tab[-2] - 1)
			return ((full_plat_run(plat, user_tab, user_tab[-2])) + sol_count);
		else if (y == user_tab[-2] - 1)
			if (user_tab[-1] == PRINT_ALL
				|| is_matching_vue(plat, user_tab, x, user_tab[-2]))
				sol_count += progress_plat(plat, x + 1, 0, user_tab);
		else
			break ;
		else
			sol_count += progress_plat(plat, x, y + 1, user_tab);
		if (sol_count > 0 && user_tab[-1] == PRINT_ONE)
			return (sol_count);
	}
	plat[x][y] = 0;
	return (sol_count);
}

int	set_options(int argc, char **argv, int *user_tab)
{
	if (argc == 3 && argv[2][0] == 'a')
		user_tab[-1] = PRINT_ALL;
	else if (argc == 3 && argv[2][0] == 'v')
		user_tab[-1] = PRINT_VALID;
	else if (argc == 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*user_tab;
	int	plat_size;
	int	**plat;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	plat_size = generate_tab(argv[1], &user_tab);
	if (!user_tab || !plat_size)
		return (1);
	user_tab[-2] = plat_size;
	if (set_options(argc, argv, user_tab))
		return (1);
	plat = malloc(sizeof(int *) * plat_size);
	init_plat(plat, plat_size);
	print_nb_sol(progress_plat(plat, 0, 0, user_tab),
		user_tab[-1] != PRINT_ONE);
	free_plat(plat, plat_size);
	free(user_tab - 2);
	return (0);
}
