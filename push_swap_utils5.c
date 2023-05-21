/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 04:29:02 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 17:07:29 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tail(t_list **stack_a)
{
	t_list	*head;

	if (!stack_a && !(*stack_a)->next)
		return (0);
	head = *stack_a;
	while (head->next != NULL)
		head = head->next;
	return (head->index);
}

int	check_if_sort(t_list **stack_a, int min)
{
	t_list	*current;

	if ((*stack_a) && (*stack_a)->next && (*stack_a)->data == min)
	{
		current = *stack_a;
		while (current->next)
		{
			if (current->data > current->next->data)
				return (1);
			current = current->next;
		}
		if (current->next == NULL)
			return (0);
	}
	return (1);
}

void	sorting(t_list **stack_a, t_list **stack_b)
{
	int		alfa_size;
	int		min;
	int		i;

	i = 1;
	alfa_size = ft_lstsize(*stack_a) * 0.15;
	min = looking_for_the_min(stack_a);
	if (!check_if_sort(stack_a, min))
		return ;
	sorting_tool(stack_a, stack_b, alfa_size, i);
}

int	sorting1_tool(t_list **stack_a, t_list **stack_b, int max, int index)
{
	if (tail(stack_b) == index && tail(stack_b) == index - 1 \
			&& tail(stack_b) == index - 2)
		rra(stack_b);
	else if ((*stack_b)->index == index - 1)
		pa(stack_a, stack_b);
	else if ((*stack_b)->index == index - 2)
	{
		pa(stack_a, stack_b);
		if ((*stack_a)->next != NULL)
			ra(stack_a);
	}
	else if ((*stack_b)->index == index)
	{
		pa(stack_a, stack_b);
		if (oh_please(stack_a, index - 1) != -1)
			sa(stack_a);
		if (oh_please(stack_a, index - 2) != -1)
			rra(stack_a);
	}
	else
		rb_rrb(stack_b, max);
	return (max);
}

int	noregret_index(t_list **stack_a, int max)
{
	t_list	*head;

	if (!(*stack_a))
		return (-1);
	head = *stack_a;
	while ((head))
	{
		if (head->data == max)
			return (head->index);
		head = head->next;
	}
	return (-1);
}
