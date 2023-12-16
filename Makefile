CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

SRC = arguments.c is_number.c malloc_fail.c free_memory.c main.c stack_operations.c interpreter.c stack_operations_2.c stack_operations_3.c stream_operations.c
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

