/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	fill_tab(int *user_tab, int max_val, int wc, char *str)
{
	int	tab_i;
	int	i;

	i = 0;
	tab_i = 0;
	while (tab_i < wc)
	{
		while (str[i] == ' ')
			i++;
		user_tab[tab_i] = ft_atoi_lite(str + i);
		if (user_tab[tab_i] > max_val || user_tab[tab_i] < 1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
		tab_i++;
	}
	user_tab[tab_i] = 0;
	return (max_val);
}

int	generate_tab(char *str, int **user_tab)
{
	int	max_val;
	int	wc;

	*user_tab = 0;
	wc = count_words(str);
	if (wc % 4)
	{
		ft_putstr("Error\n");
		return (0);
	}
	max_val = wc / 4;
	if (max_val > 9 || max_val < 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	*user_tab = malloc(sizeof(int) * (wc + 3));
	if (!(*user_tab))
		return (0);
	(*user_tab)[0] = 0;
	(*user_tab)[1] = 0;
	(*user_tab) += 2;
	return (fill_tab(*user_tab, max_val, wc, str));
}

void	print_nb_sol(int nb, int does_print)
{
	if (!does_print)
	{
		if (!nb)
			ft_putstr("Error\n");
		return ;
	}
	ft_putstr("found ");
	ft_putnbr(nb);
	ft_putstr(" solution");
	if (nb > 1)
		ft_putchar('s');
	ft_putchar('\n');
}
