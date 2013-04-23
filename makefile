INPUT_FILE=./proj3.pro
OUTPUT_DIR=vystup

all:
	@if [ ! -d $(OUTPUT_DIR) ] ; then mkdir $(OUTPUT_DIR) ; fi
	@qmake -o $(OUTPUT_DIR)/makefile $(INPUT_FILE)
	@make -C $(OUTPUT_DIR)	

clean:
	@rm -rf $(OUTPUT_DIR)

run:
	$(OUTPUT_DIR)/proj3
	
CC = g++
CFLAGS =-pedantic -Wall -W -Wextra

NAME=test

# V controller.cpp musi byt odkomentovana funkce main
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
