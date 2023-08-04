/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r')
		return (1);
	return (0);
}

// returns the length of the base or 0 if the base is invalid
int	get_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_iswhitespace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	rec_print(long long int nbr, char *base, int base_len)
{
	if (nbr >= base_len)
	{
		rec_print(nbr / base_len, base, base_len);
		rec_print(nbr % base_len, base, base_len);
	}
	else
		write(1, &base[nbr], 1);
}

void	putnbr_base_ll(long long int nbr, char *base)
{
	int	base_len;

	base_len = get_base_len(base);
	if (base_len < 2)
		return ;
	if (nbr < 0)
	{
		nbr = -nbr;
		write(1, "-", 1);
	}
	rec_print(nbr, base, base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	putnbr_base_ll(nbr, base);
}

/*
int	main(void)
{
	ft_putnbr_base(42, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(-2147483648, "01");
	ft_putchar('\n');
	ft_putnbr_base(0, "0123456789");
	ft_putchar('\n');
	ft_putnbr_base(365, "salut");
	return (0);
}
*/
