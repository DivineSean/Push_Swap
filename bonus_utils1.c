/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:59:37 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 17:00:19 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_bonus(t_list **stack_a, t_list **stack_b)
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
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (str1[i] != str2[i] || str1[i] == 0 || str2[i] == 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

int	my1(t_list **stack_a, t_list **stack_b, char *buffer, char **str)
{
	if (!ft_strncmp(buffer, "pa\n", ft_strlen("pa\n")))
		return (pa_bonus(stack_a, stack_b), 0);
	else if (!ft_strncmp(buffer, "pb\n", ft_strlen("pb\n")))
		return (pb_bonus(stack_a, stack_b), 0);
	else if (!ft_strncmp(buffer, "sa\n", ft_strlen("sa\n")))
		return (sa_bonus(stack_a), 0);
	else if (!ft_strncmp(buffer, "sb\n", ft_strlen("sb\n")))
		return (sb_bonus(stack_b), 0);
	else if (!ft_strncmp(buffer, "ss\n", ft_strlen("ss\n")))
		return (ss_bonus(stack_a, stack_b), 0);
	else if (!ft_strncmp(buffer, "ra\n", ft_strlen("ra\n")))
		return (ra_bonus(stack_a), 0);
	else if (!ft_strncmp(buffer, "rb\n", ft_strlen("rb\n")))
		return (rb_bonus(stack_b), 0);
	else if (!ft_strncmp(buffer, "rr\n", ft_strlen("rr\n")))
		return (rr_bonus(stack_a, stack_b), 0);
	else if (!ft_strncmp(buffer, "rra\n", ft_strlen("rra\n")))
		return (rra_bonus(stack_a), 0);
	else if (!ft_strncmp(buffer, "rrb\n", ft_strlen("rrb\n")))
		return (rrb_bonus(stack_b), 0);
	else if (!ft_strncmp(buffer, "rrr\n", ft_strlen("rrr\n")))
		return (rrr_bonus(stack_a, stack_b), 0);
	else
		return (write(2, "Error\n", 6), free_tab(str), \
				free_all_b(stack_a), free_all_b(stack_b), exit(0), 0);
}

void	my(t_list **stack_a, t_list **stack_b, char **str)
{
	char	*buffer;
	int		min;

	min = looking_for_the_min(stack_a);
	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			break ;
		my1(stack_a, stack_b, buffer, str);
		free(buffer);
	}
	if (!check_if_sort(stack_a, min))
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

void	sa_bonus(t_list **stack_a)
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
		tmp = (*stack_a)->next-> next;
		(*stack_a)->next->next = (*stack_a);
		(*stack_a)->next = tmp;
		*stack_a = head;
	}
}
