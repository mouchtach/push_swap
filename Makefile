NAME = push_swap.a
SOURCES = \
	ft_split.c ft_substr.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_atoi.c list.c \
	ft_add_back.c ft_add_last.c ft_new.c operations.c

OBJECTS = $(SOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

exe: all 
	@make clean
	@gcc read.c push_swap.a -o push_swap

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
