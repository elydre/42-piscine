/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
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
	write(1, &c, 1);
}

int	increment_tab(char *tab, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		if (tab[i] < '9' - (n - 1 - i))
		{
			tab[i]++;
			while (i < n - 1)
			{
				tab[i + 1] = tab[i] + 1;
				i++;
			}
			return (1);
		}
		i--;
	}
	return (0);
}

void	ft_print_combn(int n)
{
	char	tab[10];
	int		i;

	if (n > 10 || n <= 0)
		return ;
	i = 0;
	while (i < n)
	{
		tab[i] = '0' + i;
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < n)
		{
			ft_putchar(tab[i]);
			i++;
		}
		if (tab[0] != '9' - (n - 1))
			write(1, ", ", 2);
		if (!increment_tab(tab, n))
			break ;
	}
}

int	main(void)
{
	ft_print_combn(10);
	return (0);
}
