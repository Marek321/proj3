CC = g++
CFLAGS =-pedantic -Wall -W -Wextra

NAME=test

interface: mathlib.o mathlib.h controller.o
	$(CC) $(CFLAGS) mathlib.o controller.o -o controller
	
controller.o: controller.cpp	
	$(CC) $(CFLAGS) -c controller.cpp -o controller.o
	
test: mathlib.o test.o
	$(CC) $(CFLAGS) mathlib.o test.o -o test
	
mathlib.o: mathlib.cpp mathlib.h
	$(CC) $(CFLAGS) -c mathlib.cpp -o mathlib.o
	
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o