/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 03:23:35 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 03:29:10 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_word(char *str, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	i = 0;
	len = ft_strlen_checker(str, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *sr, char ch)
{
	char	**str;
	size_t	i;

	if (!sr)
		return (0);
	i = 0;
	str = (char **)malloc(sizeof(char *) * (ft_count_word(sr, ch) + 1));
	if (!str)
		exit(1);
	while (*sr != '\0')
	{
		while (*sr != '\0' && *sr == ch)
			sr++;
		if (*sr != '\0')
		{
			str[i] = ft_word(sr, ch);
			if (!(str[i]))
				return (ft_free(str, i));
			i++;
		}
		while (*sr && *sr != ch)
			sr++;
	}
	str[i] = 0;
	return (str);
}

int	isspace3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 9 && (str[i] <= 13 || str[i] == 32))
			i++;
		else
			break ;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	long	res;
	int		signe;
	int		i;

	i = isspace3(str);
	res = 0;
	signe = 1;
	if (!str[i])
		return (write(2, "Error\n", 7), exit (1), 0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			signe = signe * (-1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	ft_power(res * signe);
	return (res * signe);
}

void	sa(t_list **stack_a)
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
	write(1, "sa\n", 3);
}
