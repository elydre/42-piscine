/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_current_char01(int x, int y, int x_pos, int y_pos)
{
	if (x_pos == 0)
	{
		if (y_pos == 0)
			return ('/');
		else if (y_pos == (y - 1))
			return ('\\');
		else
			return ('*');
	}
	else if (x_pos == x - 1)
	{
		if (y_pos == 0)
			return ('\\');
		else if (y_pos == (y - 1))
			return ('/');
		else
			return ('*');
	}
	else if (y_pos == 0 || y_pos == (y - 1))
	{
		return ('*');
	}
	return (' ');
}

void	ft_rush01(int x, int y)
{
	int	x_pos;
	int	y_pos;

	y_pos = 0;
	while (y_pos < y)
	{
		x_pos = 0;
		while (x_pos < x)
		{
			ft_putchar(get_current_char01(x, y, x_pos, y_pos));
			x_pos++;
		}
		ft_putchar('\n');
		y_pos++;
	}
}
