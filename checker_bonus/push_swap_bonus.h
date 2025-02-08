#ifndef PUSH_SWAP_BONUS_H
#define PUSH_SWAP_BONUS_H

#include <fcntl.h>
#include <limits.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;

//get_next_line
char	*ft_strjoin_get(char const *s1, char const *s2);
char	*ft_strdup_get(const char *s);
size_t	ft_strlen_get(const char *s);
char	*ft_strchr_get(const char *s, int c);
char	*get_next_line(int fd);

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

//linkedlist
t_list *ft_create_stack(int **input, int count);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);

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