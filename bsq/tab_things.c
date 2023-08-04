/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_things.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = nb * -1;
	}
	else
		n = nb;
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	print_pos(t_map print)
{
	ft_putstr("pos: ");
	ft_putnbr(print.sq.x);
	ft_putstr(", ");
	ft_putnbr(print.sq.y);
	ft_putstr(" size: ");
	ft_putnbr(print.sq.size);
	ft_putchar('\n');
}

void	print_tab(int just_pos, t_map print)
{
	int	i;
	int	j;

	if (just_pos == 1)
	{
		print_pos(print);
		return ;
	}
	i = 0;
	while (i < print.nb_l)
	{
		j = 0;
		while (j < print.nb_c)
		{
			if (print.map[i][j] == 0)
				ft_putchar(print.obstacle);
			else if (print.map[i][j] == 1)
				ft_putchar(print.empty);
			else
				ft_putchar(print.full);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	free_tab(int **tab, int nb_l)
{
	int	i;

	i = 0;
	while (i < nb_l)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
