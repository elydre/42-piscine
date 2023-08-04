/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// ft_convert_base2.c functions
int		ft_iswhitespace(char c);
int		get_base_len(char *base);
void	put_in_buffer(char *buffer, char c);
int		calc_res(char *str, char *base, int i);
int		ft_atoi_base(char *str, char *base);

void	rec_print(long long int nbr, char *base, int base_len, char *res)
{
	if (nbr >= base_len)
	{
		rec_print(nbr / base_len, base, base_len, res);
		rec_print(nbr % base_len, base, base_len, res);
	}
	else
		put_in_buffer(res, base[nbr]);
}

void	savenbr_base_ll(long long int nbr, char *base, char *res)
{
	int	base_len;

	base_len = get_base_len(base);
	if (nbr < 0)
	{
		nbr = -nbr;
		put_in_buffer(res, '-');
	}
	rec_print(nbr, base, base_len, res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nbr_base10;
	char	*res;

	if (get_base_len(base_from) < 2 || get_base_len(base_to) < 2)
		return (NULL);
	nbr_base10 = ft_atoi_base(nbr, base_from);
	res = (char *) malloc(sizeof(char) * 35);
	if (!res)
		return (NULL);
	savenbr_base_ll(nbr_base10, base_to, res);
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("42:%s\n", ft_convert_base("--2a", "0123456789abcdef", "0123456789"));
	printf("max:%s\n", ft_convert_base("2147483647",
			"0123456789", "0123456789abcdef"));
	printf("illegal:%s\n", ft_convert_base("2147483647", "aa", "bb"));
}
*/
