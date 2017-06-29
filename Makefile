CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror
OBJ=parse.o list.o tree.o solution.o

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o solution

debug: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -g -o solution.dbg

solution.o: solution.c
	$(CC) $(CFLAGS) -c $<

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o &
