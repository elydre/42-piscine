/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_case(int **plat, int i, int j, int plat_size)
{
	int	x;
	int	y;

	x = 0;
	while (x < plat_size)
	{
		if (x != i && plat[x][j] == plat[i][j])
			return (0);
		x++;
	}
	y = 0;
	while (y < plat_size)
	{
		if (y != j && plat[i][y] == plat[i][j])
			return (0);
		y++;
	}
	return (1);
}

// do not care about zero
int	is_valid_plat(int **plat, int plat_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat_size)
	{
		j = 0;
		while (j < plat_size)
		{
			if (plat[i][j] != 0 && !is_valid_case(plat, i, j, plat_size))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_user_solution(int **plat, int *user_tab, int plat_size)
{
	int	i;

	i = 0;
	while (user_tab[i])
	{
		if (count_visible(plat, i / plat_size, i % plat_size, plat_size)
			!= user_tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_matching_vue(int **plat, int *user_tab, int y, int plat_size)
{
	if (count_visible(plat, 2, y, plat_size) != user_tab[plat_size * 2 + y])
		return (0);
	if (count_visible(plat, 3, y, plat_size) != user_tab[plat_size * 3 + y])
		return (0);
	return (1);
}
