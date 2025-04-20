##
## EPITECH PROJECT, 2024
## Makefile my_hunter
## File description:
## ok
##

SRC = $(shell find -name "*.c")

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include/ -g3 -Werror -Wextra -Wall

LDFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

NAME = my_hunter

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
