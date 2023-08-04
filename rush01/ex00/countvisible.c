/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countvisible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// vue = 0 -> top to bottom
int	count_vue0(int **plat, int pos, int plat_size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < plat_size)
	{
		if (plat[i][pos] > max)
		{
			max = plat[i][pos];
			count++;
		}
		i++;
	}
	return (count);
}

// vue = 1 -> bottom to top
int	count_vue1(int **plat, int pos, int plat_size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < plat_size)
	{
		if (plat[plat_size - 1 - i][pos] > max)
		{
			max = plat[plat_size - 1 - i][pos];
			count++;
		}
		i++;
	}
	return (count);
}

// vue = 2 -> left to right
int	count_vue2(int **plat, int pos, int plat_size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < plat_size)
	{
		if (plat[pos][i] > max)
		{
			max = plat[pos][i];
			count++;
		}
		i++;
	}
	return (count);
}

// vue = 3 -> right to left
int	count_vue3(int **plat, int pos, int plat_size)
{
	int	count;
	int	max;
	int	i;

	count = 0;
	max = 0;
	i = 0;
	while (i < plat_size)
	{
		if (plat[pos][plat_size - 1 - i] > max)
		{
			max = plat[pos][plat_size - 1 - i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible(int **plat, int vue, int pos, int plat_size)
{
	if (vue == 0)
		return (count_vue0(plat, pos, plat_size));
	else if (vue == 1)
		return (count_vue1(plat, pos, plat_size));
	else if (vue == 2)
		return (count_vue2(plat, pos, plat_size));
	else if (vue == 3)
		return (count_vue3(plat, pos, plat_size));
	else
		return (0);
}
