#include "push_swap.h"
#include "libft/libft.h"


void free_stack_number(int ***tab)
{
    int i = 0;
    while(*tab[i])
    {
        free(*tab[i]);
        i++;
    }
    free(*tab);
}
void free_stack_string(char **str)
{
    int i = 0;
    while(str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}
