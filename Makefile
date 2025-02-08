NAME = push_swap.a

SOURCES  = free.c input.c print.c utils_push.c sort.c \
	operations/pa.c operations/pb.c operations/ra.c operations/rb.c \
	operations/rr.c operations/rra.c operations/rrb.c operations/rrr.c \
	operations/sa.c operations/sb.c operations/ss.c \
	linkedlist/creat_list.c linkedlist/ft_add_back.c linkedlist/ft_add_last.c \
	linkedlist/ft_lstclear.c linkedlist/ft_lstnew.c linkedlist/ft_lstsize.c \
	libft/ft_atoi.c libft/ft_putstr_fd.c libft/ft_split.c libft/ft_strdup.c libft/ft_strjoin.c \
	libft/ft_strlen.c libft/ft_strncmp.c libft/ft_substr.c

BSOURCES = checker.c get_next_line.c get_next_line_utils.c \
	
	
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

exe: all 
	@$(CC) push_swap.c push_swap.a  -o push_swap

bonus: exe
	@make -C checker_bonus 
	
 
all: $(NAME) $(LIBFT)
	@make clean

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all 