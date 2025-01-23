#ifndef READ_H
#define READ_H
# include <stdlib.h>
# include <unistd.h>


typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;

t_list *ft_push_b(t_list *list_a, t_list *list_b);
t_list	*ft_lstlast(t_list *lst);
t_list *ft_list_input(int **input, int count);
t_list	*ft_lstnew(int content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif