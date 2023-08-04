/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	start_rand(t_arg *arg)
{
	t_map	grille;

	grille.nb_l = arg->y;
	grille.nb_c = arg->x;
	grille.empty = '.';
	grille.obstacle = 'o';
	grille.full = 'X';
	grille.map = gen_rand_tab(grille.nb_l, grille.nb_c, arg->prop, arg->seed);
	solve_map(&grille);
	print_tab(arg->pos, grille);
	free_tab(grille.map, grille.nb_l);
}

void	start_file(t_arg *arg)
{
	t_map	*grille;
	int		i;

	i = 0;
	while (arg->files[i])
	{
		grille = read_map(arg->files[i]);
		if (grille != NULL)
		{
			solve_map(grille);
			print_tab(arg->pos, *grille);
			if (arg->files[i + 1])
				ft_putstr("\n");
			free_tab(grille->map, grille->nb_l);
			free(grille);
		}
		else
			ft_putstr("map error\n");
		i++;
	}
}

void	start_stdin(t_arg *arg)
{
	t_map	*grille;

	grille = read_map(NULL);
	if (grille == NULL)
	{
		ft_putstr("map error\n");
		return ;
	}
	solve_map(grille);
	print_tab(arg->pos, *grille);
	free_tab(grille->map, grille->nb_l);
	free(grille);
}

void	print_help(char *name)
{
	ft_putstr("Usage: ");
	ft_putstr(name);
	ft_putstr(" [-h] [-r] [-x <int>] [-y <int>] [-s <int>] \\\n");
	ft_putstr("      [-d <int>] [-p] [<file1> <file2> ...]\n\n");
	ft_putstr("  -h: display this help\n");
	ft_putstr("  -r: generate a random map\n");
	ft_putstr("  -x: number of lines\n");
	ft_putstr("  -y: number of columns\n");
	ft_putstr("  -s: seed for random map\n");
	ft_putstr("  -d: density of obstacles\n");
	ft_putstr("  -p: print only position\n");
	ft_putstr("  <file1> <file2> ...: map files\n\n");
	ft_putstr("  If no file is specified, the map is read on the\n");
	ft_putstr("  standard input. If  -r/-x/-y/-s/-d is specified\n");
	ft_putstr("  the map is randomly generated.\n");
}

int	main(int ac, char **av)
{
	t_arg	*arg;

	arg = parsearg(ac, av);
	if (arg == (t_arg *) HELP_CODE)
	{
		print_help(av[0]);
		return (0);
	}
	if (arg == NULL)
		return (0);
	else if (arg->used_entry == 0)
		start_stdin(arg);
	else if (arg->used_entry == 1)
		start_rand(arg);
	else if (arg->used_entry == 2)
		start_file(arg);
	else
		ft_putstr("Unknown error\n");
	free(arg->files);
	free(arg);
	return (0);
}
