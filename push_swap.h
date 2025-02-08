#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <fcntl.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_list
{
	int			data;
	size_t		index;
	struct s_list	*next;
}	t_list;

//freee
void    ft_free_tab_str(char ***str);
void    ft_free_str(char **str);
void    ft_free_int(int ***tab);
void	ft_free_stack(t_list **lst);
void	ft_error();

//operations
void    sa(t_list **lst);
void    sb(t_list **lst);
void    ss(t_list **lst_a, t_list **lst_b);
void    pa(t_list **lst_a, t_list **lst_b);
void    pb(t_list **lst_a, t_list **lst_b);
void    ra(t_list **lst);
void    rb(t_list **lst);
void    rr(t_list **lst_a, t_list **lst_b);
void    rra(t_list **lst);
void    rrb(t_list **lst);
void    rrr(t_list **lst_a, t_list **lst_b);

//input
int		**get_int_arg(int argc, char **argv, int *count);

//print
void	ft_print_int_tab(int **tab);
void	ft_print_stack(t_list *lst);
void	printStacks(t_list* stack_a, t_list* stack_b);
void	printStacks_index(t_list* stack_a, t_list* stack_b);

//linkedlist
t_list *ft_create_stack(int **input, int **sorted,  int count);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content, int index);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

//sort
void 	ft_sort_tow(t_list **lst);
void 	ft_sort_three(t_list **lst);
void 	ft_sort_four(t_list **lst_a, t_list **lst_b);
void 	ft_sort_five(t_list **lst_a, t_list **lst_b);
void   ft_sort_if_tive(t_list **lst_a, t_list **lst_b, int count);

//utils
int		find_index_data(t_list *stack, int value);
void	ft_move_node_a_to_top(t_list **stack, int value);
void	ft_move_node_b_to_top(t_list **stack, int value);
int		get_min_stack(t_list *stack);
int		get_max_stack(t_list *stack);


//libft
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif