#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>

// typedef size_t t_size;

typedef struct stack
{
	struct stack *next;
	int		value;
	int		pos;
	int		cost;
} t_stack;

////	sorting functions		\\\\.

void	ft_sort(t_stack **a, t_stack **b);


////	parssing functions		\\\\.

bool		ft_parsing(t_stack **a, int ac, char **input);
bool		is_sorted(t_stack **a, int size);
bool		ft_posission(t_stack **a);
bool		ft_atoi_2d(t_stack **a, char **input);
bool		ft__atoi(t_stack **a, const char *nptr);
bool		space_exist(char *str);
bool		is_int(char *str);

////	linked list handling	\\\\.

t_stack		*ft_last(t_stack *a);
void		ft_add_back(t_stack **a, int value);
void		ft_init(t_stack *new, int value);
int			ft_stacksize(t_stack *stack_a);
void		ft_lstaddfront(t_stack **stack, t_stack *new);

////	cleaning functions		\\\\.

void		ft_clean(t_stack **a);
void		ft_free_split(char **str);

////		operations	     	\\\\.

void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);

#endif
