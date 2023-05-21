/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 08:10:06 by markik            #+#    #+#             */
/*   Updated: 2023/02/26 11:02:10 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sizeof_3_part1(t_list **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->data \
			&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		if ((*stack_a)->data > (*stack_a)->next->next->data)
			rra(stack_a);
		else
		{
			ra(stack_a);
			sa(stack_a);
			rra(stack_a);
		}
	}
	return ;
}

void	sizeof_3_part2(t_list **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data \
			&& (*stack_a)->next->data < (*stack_a)->next->next->data)
	{
		if ((*stack_a)->data < (*stack_a)->next->next->data)
			sa(stack_a);
		else
			ra(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->data \
			&& (*stack_a)->next->data > (*stack_a)->next->next->data)
	{
		sa(stack_a);
		ra(stack_a);
		ra(stack_a);
	}
	return ;
}

void	sizeof_4_part(t_list **stack_a, t_list **stack_b, int index)
{
	if (index == 1)
	{
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

int	size_of_str(char **av)
{
	int		i;
	int		j;
	char	**splite;
	int		n;

	i = 1;
	j = 0;
	while (av[i])
	{
		splite = ft_split(av[i], ' ');
		n = 0;
		if (!splite[n])
			return (write(2, "Error\n", 7), exit(1), 0);
		while (splite[n])
		{
			j++;
			n++;
		}
		free_tab(splite);
		i++;
	}
	return (j);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
