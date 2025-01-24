NAME = libft.a
SOURCES = \
	ft_split.c ft_substr.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_atoi.c \

OBJECTS = $(SOURCES:.c=.o)
AR = ar rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@make clean

$(NAME): $(OBJECTS)
	@$(AR) $@ $^

%.o: %.c libft.h
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -rf $(OBJECTS) $(BOBJECTS)
fclean: clean
	@rm -rf $(NAME)
re: fclean all 