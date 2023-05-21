/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:50:29 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 03:57:40 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (count);
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

int	searching_for_index(t_list **stack_a, int max)
{
	t_list	*head;
	int		index;

	if (!(*stack_a))
		return (-1);
	index = 1;
	head = *stack_a;
	while ((head))
	{
		if (head->data == max)
			return (index);
		index++;
		head = head->next;
	}
	return (-1);
}

int	looking_for_the_max(t_list **stack_a)
{
	t_list	*head;
	int		max;

	if (!(*stack_a))
		return (0);
	head = *stack_a;
	max = head->data;
	while (head != NULL)
	{
		if (head->data > max)
			max = head->data;
		head = head->next;
	}
	return (max);
}

int	looking_for_the_min(t_list **stack_a)
{
	t_list	*head;
	int		min;

	if (!(*stack_a))
		return (0);
	head = *stack_a;
	min = head -> data;
	while (head != NULL)
	{
		if (head->data < min)
			min = head->data;
		head = head->next;
	}
	return (min);
}

void	rb_rrb(t_list **stack_b, int max)
{
	int	index;
	int	size;

	index = searching_for_index(stack_b, max);
	size = ft_lstsize(*stack_b) / 2;
	if (index > size)
		rrb(stack_b);
	else
		rb(stack_b);
}
