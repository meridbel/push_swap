# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // mshini

typedef struct s_stack
{
    int value;
    struct s_stack *next;
} t_stack;

int check_error(char *av);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int check_valid_number(char *str);
int	ft_atoi(const char *nptr, int *num);
int is_duplicate(t_stack *head, int value);
void add_number(t_stack **head, int t);
int calc_number_in_stack(t_stack *stack_a);
void swap_a(t_stack **header);
void swap_b(t_stack **stack_b);
void swap_ab(t_stack **stack_a, t_stack **stack_b);
void push_a(t_stack **stack_a, t_stack **stack_b);
void push_b(t_stack **stack_a, t_stack **stack_b);
void rotate_a(t_stack **stack_a);
void rotate_b(t_stack **stack_b);
void rotate_ab(t_stack **stack_a, t_stack **stack_b);
void reverse_rotate_a(t_stack **stack_a);
void reverse_rotate_b(t_stack **stack_b);
void reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);

#endif