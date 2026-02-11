# Compiler
CC = gcc

# Compiler flags (e.g., -Wall enables all warnings)
CFLAGS = -Wall -g


# source files
SRC = user.c oss.c
#object files
OBJ = $(SRC:.c=.o)

OUTPUTS = user oss

# target
all: $(OUTPUTS)

# build rules

user: user.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo Built user executable
oss: oss.c
	$(CC) $(CFLAGS) -c $< -o $@
	echo Built oss executable

clean:
	rm -f *.o $(OUTPUTS)
	echo Cleaned
