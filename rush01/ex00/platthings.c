/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   platthings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_plat(int **plat, int plat_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat_size)
	{
		j = 0;
		plat[i] = malloc(sizeof(int) * plat_size);
		while (j < plat_size)
		{
			plat[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_plat(int **plat, int plat_size, int new_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < plat_size)
	{
		j = 0;
		while (j < plat_size)
		{
			ft_putchar(plat[i][j] + '0');
			if (j < plat_size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	if (new_line)
		ft_putchar('\n');
}

void	free_plat(int **plat, int plat_size)
{
	int	i;

	i = 0;
	while (i < plat_size)
	{
		free(plat[i]);
		i++;
	}
	free(plat);
}
