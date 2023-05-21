/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:30:38 by markik            #+#    #+#             */
/*   Updated: 2023/02/26 11:02:49 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**stack_b_maker(t_list **stack_a, char **data)
{
	t_list	**stack;

	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
	{
		free_all_b(stack_a);
		free_tab(data);
		exit(1);
	}
	*stack = NULL;
	return (stack);
}

void	ss_1(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*head;

	if ((!(*stack_a)) || (!(*stack_a)->next))
		return ;
	if (!(*stack_a)->next->next)
	{
		head = (*stack_a)->next;
		head->next = *stack_a;
		(*stack_a)->next = NULL;
		*stack_a = head;
	}
	else
	{
		head = (*stack_a)->next;
		tmp = (*stack_a)->next -> next;
		(*stack_a)->next->next = (*stack_a);
		(*stack_a)->next = tmp;
		*stack_a = head;
	}
}

void	ss_2(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;

	if ((!(*stack_b)) || (!(*stack_b)->next))
		return ;
	if (!(*stack_b)->next->next)
	{
		head = (*stack_b)->next;
		head->next = *stack_b;
		(*stack_b)->next = NULL;
		*stack_b = head;
	}
	else
	{
		head = (*stack_b)->next;
		tmp = (*stack_b)->next->next;
		(*stack_b)->next->next = (*stack_b);
		(*stack_b)->next = tmp;
		*stack_b = head;
	}
}

char	**add_av(char **av, char **str)
{
	char	**splite;
	int		i;
	int		j;
	int		n;

	i = 1;
	j = 0;
	while (av[i])
	{
		splite = ft_split(av[i], ' ');
		n = 0;
		while (splite[n])
		{
			str[j] = ft_strdup(splite[n]);
			if (!str[j])
				return (free_tab(splite), ft_free(str, j), exit(1), NULL);
			j++;
			n++;
		}
		free_tab(splite);
		i++;
	}
	str[j] = 0;
	return (str);
}

void	check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (av[i] && av[j] && ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				write(2, "Error\n", 7);
				free_tab(av);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return ;
}
