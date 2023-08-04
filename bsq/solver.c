/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	**dup_tab(int **old, int x, int y)
{
	int	**new;
	int	i;
	int	j;

	i = 0;
	new = malloc(sizeof(int *) * x);
	while (i < x)
	{
		j = 0;
		new[i] = (int *)malloc(sizeof(int) * y);
		while (j < y)
		{
			new[i][j] = old[i][j];
			j++;
		}
		i++;
	}
	return (new);
}

int	**calc_prox(int	**old, int x, int y)
{
	int	**new;
	int	i;
	int	j;

	i = 1;
	new = dup_tab(old, x, y);
	while (i < x)
	{
		j = 1;
		while (j < y)
		{
			if (old[i][j] == 0)
				new[i][j] = 0;
			else
				new[i][j] = 1 + ft_3min(
						new[i - 1][j],
						new[i][j - 1],
						new[i - 1][j - 1]
						);
			j++;
		}
		i++;
	}
	return (new);
}

t_sqrt	find_sqrt(int **prox, int x, int y)
{
	t_sqrt	sqrt;
	int		i;
	int		j;

	i = 0;
	sqrt.size = 0;
	sqrt.x = -1;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (prox[i][j] > sqrt.size)
			{
				sqrt.size = prox[i][j];
				sqrt.x = i;
				sqrt.y = j;
			}
			j++;
		}
		i++;
	}
	return (sqrt);
}

void	fill_sol(int **sol, t_sqrt sqrt)
{
	int	i;
	int	j;

	if (sqrt.x == -1)
		return ;
	i = sqrt.x;
	while (i > sqrt.x - sqrt.size)
	{
		j = sqrt.y;
		while (j > sqrt.y - sqrt.size)
		{
			sol[i][j] = 2;
			j--;
		}
		i--;
	}
}

void	solve_map(t_map *print)
{
	int		**prox;
	t_sqrt	sq;

	prox = calc_prox(print->map, print->nb_l, print->nb_c);
	sq = find_sqrt(prox, print->nb_l, print->nb_c);
	print->sq.x = sq.x - sq.size + 1;
	print->sq.y = sq.y - sq.size + 1;
	print->sq.size = sq.size;
	fill_sol(print->map, sq);
	free_tab(prox, print->nb_l);
}
