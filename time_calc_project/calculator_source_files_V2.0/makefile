#makefile for calculator
#Author: Jeremy Leclerc


CFLAGS = -Wall -Wextra -c
CC = gcc

.PHONY: clean

calculator: time_calc.o time_spec.o seconds.o time_arg.o time_calc.h
	$(CC) time_calc.o time_spec.o seconds.o time_arg.o -o calculator

time_calc.o: time_calc.h
	$(CC) $(CFLAGS) time_calc.c

time_spec.o: time_spec.h
	$(CC) $(CFLAGS) time_spec.c

seconds.o: seconds.h
	$(CC) $(CFLAGS) seconds.c

time_arg.o: time_arg.h
	$(CC) $(CFLAGS) time_arg.c

clean:
	rm -f time_calc.o time_spec.o seconds.o time_arg.o
	rm -f calculator


