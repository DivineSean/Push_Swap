/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 07:52:39 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 18:01:28 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sizeof_2(t_list **stack_a)
{
	if ((*stack_a)->data < (*stack_a)->next->data)
		return ;
	else
		ra(stack_a);
}

void	sizeof_3(t_list **stack_a)
{
	int	min;

	min = looking_for_the_min(stack_a);
	if (!check_if_sort(stack_a, min))
		return ;
	sizeof_3_part1(stack_a);
	sizeof_3_part2(stack_a);
}

void	sizeof_4(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	index;

	min = looking_for_the_min(stack_a);
	if (!check_if_sort(stack_a, min))
		return ;
	index = searching_for_index(stack_a, min);
	sizeof_4_part(stack_a, stack_b, index);
	sizeof_3(stack_a);
	pa(stack_a, stack_b);
	return ;
}

void	ra_rra(t_list **stack_a, int min, int size)
{
	if (searching_for_index(stack_a, min) <= size / 2)
		ra(stack_a);
	else
		rra(stack_a);
}

void	sizeof_5(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	index;
	int	i;

	i = 2;
	min = looking_for_the_min(stack_a);
	if (!check_if_sort(stack_a, min))
		return ;
	while (i > 0)
	{
		min = looking_for_the_min(stack_a);
		index = searching_for_index(stack_a, min);
		if (index == 1)
		{
			pb(stack_a, stack_b);
			i--;
		}
		else
			ra_rra(stack_a, min, 5);
	}
	sizeof_3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	return ;
}
