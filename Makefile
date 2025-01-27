NAME = push_swap.a
LIBFT = libft/libft.a
SOURCES = \
	input.c \
	free.c \
	linkedlist/ft_add_back.c \
	linkedlist/ft_add_last.c \
	linkedlist/ft_new.c \
	linkedlist/creat_list.c \
	linkedlist/ft_lstclear.c \
	linkedlist/ft_lstsize.c \
	operations/push.c \
	operations/rotate.c \
	operations/swap.c \
	print_stack.c

OBJECTS = $(SOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

exe: all 
	make clean
	gcc push_swap.c push_swap.a  $(LIBFT) -o push_swap
	make clean


all: $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all 
