/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:23:33 by markik            #+#    #+#             */
/*   Updated: 2023/02/25 05:30:13 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *src)
{
	char		*dest;
	size_t		src_size;

	src_size = ft_strlen(src);
	dest = malloc(sizeof (char) * (src_size + 1));
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}

void	free_all_b(t_list **list)
{
	if (!(*list))
		return ;
	if ((*list)->next)
		free_all_b(&(*list)->next);
	free(*list);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

t_list	*new_node(int data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list	**stack_maker(char **data)
{
	int		i;
	t_list	**stack;
	t_list	*node;
	int		num;

	i = ft_strlen1(data);
	stack = (t_list **)malloc(sizeof(t_list *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	while (--i >= 0)
	{
		num = ft_atoi(data[i]);
		node = new_node(num);
		if (!node)
		{
			ft_free(data, i);
			free(stack);
			exit(1);
		}
		node->next = *stack;
		*stack = node;
	}
	return (stack);
}
