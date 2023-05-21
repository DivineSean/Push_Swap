/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:57:28 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 16:58:44 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb_bonus(t_list **stack_b)
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
}

void	ss_bonus(t_list **stack_a, t_list **stack_b)
{
	ss_1(stack_a);
	ss_2(stack_b);
}

void	pa_bonus(t_list **stack_a, t_list **stack_b)
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
}

void	pb_bonus(t_list **stack_a, t_list **stack_b)
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
	stack_b = NULL;
	stack_b = stack_b_maker(stack_a, str);
	my(stack_a, stack_b, str);
	free_tab(str);
	return (free_all_b(stack_a), free_all_b(stack_b), exit(0), 0);
}
