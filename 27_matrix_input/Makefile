CC = gcc
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
CFLAGS = -std=gnu99 -pedantic -Wall -O3
rotateMatrix: rotateMatrix.c
	$(CC) $(CFLAGS) -o $@ $^
rotateMatrix-debug: rotateMatrix.c
	$(CC) $(DBGFLAGS) -o $@ $^
