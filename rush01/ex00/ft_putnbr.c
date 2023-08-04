/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	int_length(int n)
{
	int	length;

	length = 0;
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

int	get_digit(int n, int digit)
{
	int	i;

	i = 0;
	while (i < digit)
	{
		n /= 10;
		i++;
	}
	return (n % 10);
}

void	ft_putnbr(int nb)
{
	int	length;
	int	i;

	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	else if (nb == 0)
	{
		ft_putchar('0');
	}
	length = int_length(nb);
	i = 0;
	while (i < length)
	{
		ft_putchar(get_digit(nb, length - i - 1) + '0');
		i++;
	}
}
