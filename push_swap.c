/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:17:59 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 17:05:05 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_maker(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*curr;
	int		index;

	curr = *stack_a;
	while (curr != NULL)
	{
		tmp = *stack_a;
		index = 1;
		while (tmp != NULL)
		{
			if (tmp->data < curr->data)
				index++;
			tmp = tmp->next;
		}
		curr->index = index;
		curr = curr->next;
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**str;

	if (ac == 1)
		exit(1);
	str = malloc(sizeof(char *) * (size_of_str(av) + 1));
	if (!str)
		exit(1);
	str = add_av(av, str);
	check_duplicate(str);
	check_greater_than_max_int(str);
	check_num(str);
	stack_a = stack_maker(str);
	if (!stack_a)
		return (free_tab(str), 0);
	index_maker(stack_a);
	stack_b = NULL;
	stack_b = stack_b_maker(stack_a, str);
	mysorting(ft_strlen1(str), stack_a, stack_b);
	free_tab(str);
	return (free_all_b(stack_a), free_all_b(stack_b), exit(0), 0);
}
