/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:59:26 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 16:59:27 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_bonus(t_list **stack_a)
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
}

void	rb_bonus(t_list **stack_b)
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
}

void	rr_bonus(t_list **stack_a, t_list **stack_b)
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
}

void	rra_bonus(t_list **stack_a)
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
}

void	rrb_bonus(t_list **stack_b)
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
}
