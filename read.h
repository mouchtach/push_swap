#ifndef READ_H
#define READ_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int			data;
	struct s_list	*next;
}	t_list;

int	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif