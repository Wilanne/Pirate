# Default rule
EXEC = Jeu
CC = gcc
LD = gcc

CCFLAGS = -g -pedantic -pedantic-errors -Wall -fsanitize=address 
LDFLAGS = -fsanitize=address
RM = rm -f

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

# Compilation rules
all: $(EXEC)

$(EXEC): $(OBJ)
	$(LD) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

# Clean the project
clean:
	$(RM) *.o $(EXEC)