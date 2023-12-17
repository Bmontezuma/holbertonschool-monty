CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = add.c memory.c nop.c pall.c pint.c pop.c push.c main.c swap.c process_instructions.c cleanup.c
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

