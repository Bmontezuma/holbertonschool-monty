CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = main.c opcodes.c parse_instruc.c
OBJ = $(SRC:.c=.o)
EXEC = monty

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re
