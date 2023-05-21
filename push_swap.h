/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: markik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:36:19 by markik            #+#    #+#             */
/*   Updated: 2023/03/01 17:25:23 by markik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct node
{
	int			data;
	int			index;
	struct node	*next;
}t_list;

t_list	**stack_b_maker(t_list **stack_a, char **data);
t_list	**stack_maker(char **data);
t_list	*new_node(int data);
size_t	ft_strlen_checker(char *s, char c);
size_t	ft_count_word(char *s, char c);
int		ft_power(long n);
void	mysorting(int ac, t_list **stack_a, t_list **stack_b);
void	ft_strcat(char *str, char *dest, char *src);
void	sorting(t_list **stack_a, t_list **stack_b);
void	sorting1(t_list **stack_a, t_list **stack_b);
void	sizeof_3_part1(t_list **stack_a);
void	sizeof_3_part2(t_list **stack_a);
void	sizeof_4_part(t_list **stack_a, t_list **stack_b, int index);
void	sorting_tool(t_list **stack_a, t_list **stack_b, int alfa_size, int i);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	check_greater_than_max_int(char **av);
void	ra_rra(t_list **stack_a, int min, int size);
void	rb_rrb(t_list **stack_b, int max);
char	**ft_free(char **str, size_t j);
char	*ft_strjoin(char *s1, char *s2);
void	check_duplicate(char **av);
void	sizeof_2(t_list **stack_a);
void	sizeof_3(t_list **stack_a);
void	sizeof_4(t_list **stack_a, t_list **stack_b);
void	sizeof_5(t_list **stack_a, t_list **stack_b);
void	free_all_b(t_list **list);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	ss_1(t_list **stack_a);
void	ss_2(t_list **stack_b);
void	free_tab(char **tab);
char	*ft_strcpy(char *dest, char *src);
char	**add_av(char **av, char **str);
char	**ft_split(char *str, char caractere);
char	*ft_strchr(char *s, int c);
char	*ft_word(char *str, char caractere);
char	*ft_reading_to_stock(int fd, char *stock);
char	*ft_liner(char *stock);
char	*ft_stockage(char *stock);
char	*get_next_line(int fd);
int		ft_strlen1(char **str);
char	*ft_strdup(char *src);
int		sorting1_tool(t_list **stack_a, t_list **stack_b, int max, int index);
int		searching_for_index(t_list **stack_a, int max);
int		check_if_sort(t_list **stack_a, int min);
int		check_num_tool(char **av, int i, int j);
int		looking_for_the_min(t_list **stack_a);
int		looking_for_the_max(t_list **stack_a);
int		tail(t_list **stack_a);
int		ft_lstsize(t_list *lst);
int		check_num(char **av);
int		ft_strlen(char *str);
int		isspace3(char *str);
int		ft_atoi(char *str);
int		size_of_str(char **av);
int		noregret_index(t_list **stack_a, int max);
int		oh_please(t_list **stack_a, int index);
void	ra_bonus(t_list **stack_a);
void	rb_bonus(t_list **stack_b);
void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	rra_bonus(t_list **stack_a);
void	rrb_bonus(t_list **stack_b);
void	rrr_bonus(t_list **stack_a, t_list **stack_b);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		my1(t_list **stack_a, t_list **stack_b, char *buffer, char **str);
void	my(t_list **stack_a, t_list **stack_b, char **str);
void	sa_bonus(t_list **stack_a);
void	sb_bonus(t_list **stack_b);
void	ss_bonus(t_list **stack_a, t_list **stack_b);
void	pa_bonus(t_list **stack_a, t_list **stack_b);
void	pb_bonus(t_list **stack_a, t_list **stack_b);
#endif
