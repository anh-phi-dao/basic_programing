SRC:=src/%.c #usage of wildcard
INC:=include
BUILD:=src/%.o
SRC_LIST:=$(wildcard src/*.c)
OBJECT:=$(SRC_LIST:src/%.c=src/%.o)
CC:=gcc
TEMP_FLAG:=-save-temps
CFLAG:=-c -Wall  -g $(TEMP_FLAG)
LFLAG:= -Xlinker -Map=main.map -g $(TEMP_FLAG)
INC_FLAG:= -I$(INC)/

#build all target
.PHONY: all
all: main
	@echo "You can run the program"

#build relocatable object file
$(BUILD): $(SRC) 
	$(CC) $(CFLAG) $^ -o $@ $(INC_FLAG)

#build executable file
main: $(OBJECT)
	$(CC) $(LFLAG)  $^ -o $@ 
	objdump -h src/main.o
	@size main
	@echo "$@ program has been compiled sucessfully"

#debug command
.PHONY: debug
debug: main
	@gdb main

#execute the program
.PHONY: excecute
excecute: main
	@./main

#clean the program and unessesary file
.PHONY: clean
clean:
	- rm *.i
	- rm *.s 
	- rm *.o 
	- rm *.map
	- rm *.txt 
	- rm main 
	




