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

/*
 
   -x -> largeur
   -y -> hauteur
   -v -> version
   -h -> help

*/

#include <unistd.h>
#define ERROR_WRONG_FLAG -1
#define ERROR_WRONG_ARGUMENT -2

#define ARG_X 0
#define ARG_Y 1
#define ARG_V 2

void	ft_rush00(int x, int y);
void	ft_rush01(int x, int y);
void	ft_rush02(int x, int y);
void	ft_rush(int x, int y);
void	ft_rush04(int x, int y);

void	print_help(void)
{
	char	*help;

	help = 
		"\t _________________________________________________ \n"
		"\t|     rush 00 - RECTANGLE GENERATOR               |\n"
		"\t|                                                 |\n"
		"\t|  Usage: ./XX [FLAGS]                            |\n"
		"\t|_________________________________________________|\n"
		"\t|              |                                  |\n"
		"\t| -v, -voiture | Choose rush level       | def: 3 |\n"
		"\t| -x, -xavier  | Choose rectangle width  | def: 5 |\n"
		"\t| -y, -yeti    | Choose rectangle height | def: 5 |\n"
		"\t|______________|__________________________________|\n"
		"\t|              |                                  |\n"
		"\t| -h, -hiboux  | Give this help list              |\n"
		"\t|______________|__________________________________|\n\n\n";
	write(1, help, 690);
}

int	ft_atoi(char *str)
{
	unsigned int	result;
	unsigned int	i;

	i = 0;
	result = 0;
	if (str == NULL || str[0] == '-')
		return (ERROR_WRONG_ARGUMENT);
	while (str[i] != '\0')
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (ERROR_WRONG_ARGUMENT);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result);
}

void	init_args(int *args)
{
	args[ARG_X] = 5;
	args[ARG_Y] = 5;
	args[ARG_V] = 3;
}

int	ft_parse(int *r, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'v')
				r[ARG_V] = ft_atoi(argv[i + 1]);
			else if (argv[i][1] == 'x')
				r[ARG_X] = ft_atoi(argv[i + 1]);
			else if (argv[i][1] == 'y')
				r[ARG_Y] = ft_atoi(argv[i + 1]);
			else if (argv[i][1] == 'h')
				return (1);
			else
				return (ERROR_WRONG_FLAG);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		parsing_output;
	int		args[3];

	init_args(args);
	parsing_output = ft_parse(args, argc, argv);
	if (parsing_output == 1)
		print_help();
	else if (parsing_output == ERROR_WRONG_FLAG)
		return (write(1, "WRONG FLAG, SEE HELP WITH -h FOR MORE\n", 37) || 1);
	else if (args[ARG_X] == ERROR_WRONG_ARGUMENT
		|| args[ARG_Y] == ERROR_WRONG_ARGUMENT)
		return (write(1, "WRONG SIZE ARGUMENT, SEE HELP WITH -h\n", 37) || 1);
	else if (args[ARG_V] == ERROR_WRONG_ARGUMENT)
		return (write(1, "WRONG VERSION, SEE HELP WITH -h FOR MORE\n", 40) || 1);
	else if (args[ARG_V] == 0)
		ft_rush00(args[ARG_X], args[ARG_Y]);
	else if (args[ARG_V] == 1)
		ft_rush01(args[ARG_X], args[ARG_Y]);
	else if (args[ARG_V] == 2)
		ft_rush02(args[ARG_X], args[ARG_Y]);
	else if (args[ARG_V] == 3)
		ft_rush(args[ARG_X], args[ARG_Y]);
	else if (args[ARG_V] == 4)
		ft_rush04(args[ARG_X], args[ARG_Y]);
	return (0);
}
