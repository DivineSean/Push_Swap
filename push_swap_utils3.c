/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:42:45 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 03:50:11 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	head = (*stack_b)->next;
	current = *stack_b;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_b;
	(*stack_b)->next = NULL;
	*stack_b = head;
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
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
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	head = (*stack_b)->next;
	current = *stack_b;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack_b;
	(*stack_b)->next = NULL;
	*stack_b = head;
	write(1, "rr\n", 3);
}

void	rra(t_list **stack_a)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	current = *stack_a;
	while (current->next->next != NULL)
		current = current->next;
	head = current->next;
	head->next = *stack_a;
	*stack_a = head;
	current->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	current = *stack_b;
	while (current->next->next != NULL)
		current = current->next;
	head = current->next;
	head->next = *stack_b;
	*stack_b = head;
	current->next = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*current;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	current = *stack_a;
	while (current->next->next != NULL)
		current = current->next;
	head = current->next;
	head->next = *stack_a;
	*stack_a = head;
	current->next = NULL;
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	current = *stack_b;
	while (current->next->next != NULL)
		current = current->next;
	head = current->next;
	head->next = *stack_b;
	*stack_b = head;
	current->next = NULL;
	write(1, "rrr\n", 4);
}
