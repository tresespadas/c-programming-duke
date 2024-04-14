CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -O3

power.o: power.c
	$(CC) $(CFLAGS) -c $<
test-power.o: test-power.c
	$(CC) $(CFLAGS) -c $<
power: power.o test-power.o
	$(CC) $(CFLAGS) -o $@ $^
