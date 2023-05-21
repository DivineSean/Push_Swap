/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:03:33 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 05:23:14 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_power(long n)
{
	int	power;

	power = 0;
	if (n <= 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		power++;
	}
	if (power > 10)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
	return (power);
}

void	check_greater_than_max_int(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_strchr(av[i], '-') && ft_atoi(av[i]) < 0)
		{
			write(2, "Error\n", 7);
			free_tab(av);
			exit(1);
		}
		else if (ft_strchr(av[i], '-') && ft_atoi(av[i]) > 0)
		{
			write(2, "Error\n", 7);
			free_tab(av);
			exit(1);
		}
		i++;
	}
	return ;
}

int	check_num_tool(char **av, int i, int j)
{
	if (av[i][j + 1] == ' ' || av[i][j + 1] == '\0')
		return (write(2, "Error\n", 7), exit(1), 0);
	else if (j != 0 && av[i][j - 1] != ' ')
		return (write(2, "Error\n", 7), exit(1), 0);
	else
		j++;
	return (j);
}

int	check_num(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] >= 48 && av[i][j] <= 57)
				j++;
			else
			{
				if (av[i][j] == '+' || av[i][j] == '-')
				{
					j = check_num_tool(av, i, j);
				}
				else
					return (write(2, "Error\n", 7), free_tab(av), exit(1), 0);
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
