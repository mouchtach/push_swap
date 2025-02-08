NAME = checker.a

SOURCES = libft_bonus/ft_atoi.c libft_bonus/ft_putstr_fd.c libft_bonus/ft_split.c \
	libft_bonus/ft_strdup.c libft_bonus/ft_strjoin.c libft_bonus/ft_strlen.c libft_bonus/ft_strncmp.c \
	libft_bonus/ft_substr.c \
	linkedlist_bonus/creat_list.c linkedlist_bonus/ft_add_back.c linkedlist_bonus/ft_add_last.c \
	linkedlist_bonus/ft_lstclear.c linkedlist_bonus/ft_lstnew.c linkedlist_bonus/ft_lstsize.c \
	operations_bonus/pa.c operations_bonus/pb.c operations_bonus/ra.c operations_bonus/rb.c \
	operations_bonus/rr.c operations_bonus/rra.c operations_bonus/rrb.c operations_bonus/rrr.c \
	operations_bonus/sa.c operations_bonus/sb.c operations_bonus/ss.c \
	get_next_line.c get_next_line_utils.c input_bonus.c free_bonus.c\

OBJECTS = $(SOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

exe: all 
	@$(CC) checker.c checker.a  -o ../checker

all: $(NAME)
	@make clean

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c push_swap_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
