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
