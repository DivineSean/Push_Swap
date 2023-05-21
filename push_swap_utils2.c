/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:29:22 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 03:37:38 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head;

	if ((!(*stack_b)) || (!(*stack_b)->next))
		return ;
	if (!(*stack_b)-> next->next)
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
	write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	ss_1(stack_a);
	ss_2(stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_b))
		return ;
	current = *stack_b;
	head = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = current;
	(*stack_b) = head;
	write (1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a))
		return ;
	current = *stack_a;
	head = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = current;
	(*stack_a) = head;
	write (1, "pb\n", 3);
}

void	ra(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	head = (*stack_a)->next;
	current = *stack_a;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_a;
	(*stack_a)->next = NULL;
	*stack_a = head;
	write(1, "ra\n", 3);
}
