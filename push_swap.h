#ifndef PUSH_SWAP_READ_H
#define PUSH_SWAP_READ_H

# include <stdlib.h>
# include <unistd.h>


typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;

void 	ft_push_b(t_list **list_a, t_list **list_b);
t_list	*ft_lstlast(t_list *lst);
t_list *ft_list_input(int **input, int count);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);



#endif