/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*                                                     #+#    #+#             */
/*                                                    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	char	j;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		j = str[i];
		if (!((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z')))
			return (0);
		i++;
	}
	return (1);
}

/*
int	main(void)
{
	printf("hello: %d\n", ft_str_is_alpha("hello"));
	printf("HelloWorld: %d\n", ft_str_is_alpha("HelloWorld"));
	printf("HelloWorld123: %d\n", ft_str_is_alpha("Hello World 123"));

	return (0);
}
*/
