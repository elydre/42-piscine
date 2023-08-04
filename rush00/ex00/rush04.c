/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	get_current_char04(int x, int y, int x_pos, int y_pos)
{
	if (x_pos == 0)
	{
		if (y_pos == 0)
			return ('A');
		else if (y_pos == (y - 1))
			return ('C');
		else
			return ('B');
	}
	else if (x_pos == x - 1)
	{
		if (y_pos == 0)
			return ('C');
		else if (y_pos == (y - 1))
			return ('A');
		else
			return ('B');
	}
	else if (y_pos == 0 || y_pos == (y - 1))
	{
		return ('B');
	}
	return (' ');
}

void	ft_rush04(int x, int y)
{
	int	x_pos;
	int	y_pos;

	y_pos = 0;
	while (y_pos < y)
	{
		x_pos = 0;
		while (x_pos < x)
		{
			ft_putchar(get_current_char04(x, y, x_pos, y_pos));
			x_pos++;
		}
		ft_putchar('\n');
		y_pos++;
	}
}
