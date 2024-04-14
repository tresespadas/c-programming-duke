CC = gcc
DBGFLAGS = -std=gnu99 -pedantic -Wall -ggdb3 -DDEBUG
CFLAGS = -std=gnu99 -pedantic -Wall -O3
breaker: breaker.c
	$(CC) $(CFLAGS) -o $@ $^
breaker-debug: breaker.c
	$(CC) $(DBGFLAGS) -o $@ $^
