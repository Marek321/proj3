CC = g++
CFLAGS =-pedantic -Wall -W -Wextra

NAME=test

build: mathlib.o $(NAME).o
	$(CC) $(CFLAGS) mathlib.o $(NAME).o -o $(NAME)
	
mathlib.o: mathlib.cpp mathlib.h
	$(CC) $(CFLAGS) -c mathlib.cpp -o mathlib.o
	