/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;
	int	i;

	res = 1;
	i = 0;
	if (power < 0)
		return (0);
	while (i < power)
	{
		res *= nb;
		i++;
	}
	return (res);
}

/*
#include <stdio.h>

int main()
{
	printf("%d", ft_iterative_power(12, 0));
}
*/
