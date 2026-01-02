/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meridbel <meridbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 19:27:26 by meridbel          #+#    #+#             */
/*   Updated: 2026/01/01 21:45:54 by meridbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

int		check_error(char *av);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		check_valid_number(char *str);
int		ft_atoi(const char *nptr, int *num);
int		is_duplicate(t_stack *head, int value);
void	add_number(t_stack **head, int t);
int		calc_number_in_stack(t_stack *stack_a);
void	swap_a(t_stack **header);
void	swap_b(t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a);
int		greater_than(t_stack *header);
void	sort_three_numbers(t_stack **stack_a);
void	four_numbers(t_stack **stack_a, t_stack **stack_b);
void	the_big_algo(t_stack **stack_a, t_stack **stack_b,
			int numbers_in_stack);
void	the_big_algo_2(t_stack **stack_a, t_stack **stack_b);
void	helper_of_a_to_b(t_stack **stack_b, t_stack **stack_a,
			int limit, int chunk);
int		index_of_next_chunk(t_stack *a, int limit);
int		helper_of_start_function(char	**split, t_stack **stack_a,
			int *numbers, int i);
char	**ftt_free(char **split);
void	free_stack(t_stack *stack_a);

#endif
