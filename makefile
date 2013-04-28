INPUT_FILE=./proj3.pro
OUTPUT_DIR=bin
OUTPUT_FILE=gscalc

all:
	@if [ ! -d $(OUTPUT_DIR) ] ; then mkdir $(OUTPUT_DIR) ; fi
	@qmake -o $(OUTPUT_DIR)/makefile $(INPUT_FILE)
	@make -C $(OUTPUT_DIR)	

clean:
	@rm -rf $(OUTPUT_DIR)

run:
	$(OUTPUT_DIR)/$(OUTPUT_FILE)
	
CC = g++
CFLAGS =-pedantic -Wall -W -Wextra

NAME=test

# V controller.cpp musi byt odkomentovana funkce main
interface: mathlib.o mathlib.h controller.o
	$(CC) $(CFLAGS) mathlib.o controller.o -o controller
	
controller.o: controller.cpp	
	$(CC) $(CFLAGS) -c controller.cpp -o controller.o
	
test: mathlib.o test.o
	@echo "Prekladam testovaci program"
	gcc -std=c99 -pedantic -Wall -W -Wextra mathlib.o test.o -o test
	@rm -f mathlib.o test.o
	./test
	
mathlib.o: mathlib.cpp mathlib.h
	$(CC) $(CFLAGS) -c mathlib.cpp -o mathlib.o
	
test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o test.o
doc:
	doxygen
	
install: $(OUTPUT_DIR)/$(OUTPUT_FILE)
	cp $(OUTPUT_DIR)/$(OUTPUT_FILE) /usr/bin

uninstall: 
	rm -f /usr/bin/$(OUTPUT_FILE)
