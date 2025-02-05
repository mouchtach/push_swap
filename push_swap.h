#ifndef PUSH_SWAP_READ_H
#define PUSH_SWAP_READ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"


typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;

int		**number_arg(int argc, char **argv, int *count);
void    ft_print_stacks(t_list *stack_a, t_list *stack_b);
void    ft_sort_th(t_list **stack_a);

// operations
void	ft_push_a(t_list **list_a, t_list **list_b);
void 	ft_push_b(t_list **list_a, t_list **list_b);
void	ft_swap(t_list **list);
void    ft_ss_swap(t_list **list_a,  t_list **list_b);
void	ft_rotate(t_list **list);
void    ft_rr_rotate(t_list **list_a, t_list **list_b);
void	ft_rerotate(t_list **list);
void    ft_rr_rerotate(t_list **list_a, t_list **list_b);

// linked list
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_list_input(int **input, int count);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);

//free
void	free_stack_number(int ***tab);
void	free_stack_string(char **str);
void	ft_lstclear(t_list **lst);

#endif