#GENERAL SYNTAX
#target: dependencies
#	command

CC=gcc
CFLAGS=-g -pedantic -Wall -Wextra -Wstrict-prototypes -std=c99

# name of final binary
PRG=test_avl

all: avl_tree.o $(PRG)

$(PRG): avl_tree.o student.c
	$(CC) $(CFLAGS) student.c avl_tree.o -o $(PRG)
avl_tree.o: avl_tree.h avl_tree.c
	$(CC) $(CFLAGS) -c avl_tree.c -o avl_tree.o

clean:
	rm *.o $(PRG)

