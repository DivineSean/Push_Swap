/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils11.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:05:21 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 17:19:59 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	oh_please(t_list **stack_a, int index)
{
	t_list	*head;

	if (!(*stack_a))
		return (-1);
	head = *stack_a;
	while ((head))
	{
		if (head->index == index)
			return (0);
		head = head->next;
	}
	return (-1);
}

void	sorting1(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	index;

		max = looking_for_the_max(stack_b);
	while ((*stack_b))
	{
		max = looking_for_the_max(stack_b);
		index = noregret_index(stack_b, max);
		max = sorting1_tool(stack_a, stack_b, max, index);
	}
}

void	mysorting(int len, t_list **stack_a, t_list **stack_b)
{
	if (len == 1)
		exit(1);
	else if (len == 2)
		sizeof_2(stack_a);
	else if (len == 3)
		sizeof_3(stack_a);
	else if (len == 4)
		sizeof_4(stack_a, stack_b);
	else if (len == 5)
		sizeof_5(stack_a, stack_b);
	else
	{
		sorting(stack_a, stack_b);
		sorting1(stack_a, stack_b);
	}
	return ;
}

void	sorting_tool(t_list **stack_a, t_list **stack_b, int alfa_size, int i)
{
	int	j;

	j = 0;
	while (*stack_a)
	{
		if (j == i + alfa_size)
			i = i + alfa_size;
		else if ((*stack_a)->index >= i && (*stack_a)->index <= i + alfa_size)
		{
			pb(stack_a, stack_b);
			j++;
		}
		else if (tail(stack_a) && tail(stack_a) >= i \
				&& tail(stack_a) <= i + alfa_size)
		{
			rra(stack_a);
			pb(stack_a, stack_b);
			j++;
		}
		else
			ra(stack_a);
	}
}
