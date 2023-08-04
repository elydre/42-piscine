/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// bubble sort like
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < size)
	{
		while (j < size - 1)
		{
			if (tab[j + 1] < tab[j])
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
				j = 0;
			}
			else
				j++;
		}
		i++;
	}
}

/*
int	main(void)
{
	int	tab[10] = {1, 5, 3, 4, 2, 6, 7, 8, 9, 0};
	int	i;

	i = 0;
	ft_sort_int_tab(tab, 10);
	while (i < 10)
	{
		printf("%d ", tab[i]);
		i++;
	}
	return (0);
}
*/
