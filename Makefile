NAME = push_swap.a
LIBFT = ./libft/libft.a
SOURCES = \
	./linkedlist/ft_add_back.c \
	./linkedlist/ft_add_last.c \
	./linkedlist/ft_new.c \
	./linkedlist/creat_list.c \
	./operations/operations.c \

OBJECTS = $(SOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

exe: all 
	@make clean
	@gcc read.c push_swap.a  $(LIBFT) -o push_swap

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all 
