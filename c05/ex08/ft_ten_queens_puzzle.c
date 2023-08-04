/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_print_game(int *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(game[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int	check(int *game, int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (game[i] == col)
			return (0);
		if (game[i] - i == col - row)
			return (0);
		if (game[i] + i == col + row)
			return (0);
		i++;
	}
	return (1);
}

int	find_solution(int *game, int row)
{
	int	solutions;
	int	col;

	col = 0;
	solutions = 0;
	if (row == 10)
	{
		ft_print_game(game);
		return (1);
	}
	while (col < 10)
	{
		if (check(game, row, col))
		{
			game[row] = col;
			solutions += find_solution(game, row + 1);
		}
		col++;
	}
	return (solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	game[10];

	return (find_solution(game, 0));
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}
*/
