/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	mod_putchar(char c, int mode)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (mode == 1)
		write(1, &c, 1);
	else
	{
		write(1, &hex[c / 16], 1);
		write(1, &hex[c % 16], 1);
	}
}

void	print_hex_addr(unsigned long long addr)
{
	char	*hex;
	char	rev[16];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (addr)
	{
		rev[i] = hex[addr % 16];
		addr /= 16;
		i++;
	}
	while (i < 16)
	{
		rev[i] = '0';
		i++;
	}
	while (i > 0)
	{
		i--;
		mod_putchar(rev[i], 1);
	}
}

void	print_ascii(unsigned char *str, unsigned int i, unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16 && i + j < size)
	{
		if (str[i + j] < 32 || str[i + j] > 126)
			mod_putchar('.', 1);
		else
			mod_putchar(str[i + j], 1);
		j++;
	}
	mod_putchar('\n', 1);
}

void	*print_memory(const void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*str;

	str = (unsigned char *) addr;
	i = 0;
	while (i < size)
	{
		print_hex_addr((unsigned long long) &str[i]);
		write(1, ": ", 2);
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				mod_putchar(str[i + j], 0);
			else
				write(1, "  ", 2);
			if (j % 2)
				mod_putchar(' ', 1);
			j++;
		}
		print_ascii(str, i, size);
		i += 16;
	}
	return ((void *) addr);
}

/*
int	main(void)
{
	char	*tab;

	tab = "abcdefghijklmnopqrstuvwxyz\n0123456789\n";
	print_memory(tab, 40);
	return (0);
}
*/
