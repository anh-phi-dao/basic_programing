SRC:=src/%.c #usage of wildcard
INC:=include/
BUILD:=src/%.o
DEP:=include/%.h
SRC_LIST:=$(wildcard src/*.c)
OBJECT:=$(SRC_LIST:src/%.c=src/%.o)
CC:=gcc
CFLAGS:=-Wall
LFLAGS:=$(TEMP_FLAG)
INC_FLAG:= -I$(INC)



#build all target
.PHONY: all
all: testing
	@echo "You can run the program"

#build relocatable object file
$(BUILD): $(SRC) 
	$(CC) -c $^ -o $@ $(INC_FLAG) $(CFLAGS)

#build executable file
testing: $(OBJECT)
	$(CC) $(LFLAGS)  $^ -o $@ 
	@echo "$@ program has been compiled sucessfully"


#clean the program and unessesary file
.PHONY: clean
clean:
	- rm *.i
	- rm *.s 
	- rm *.o 
	- rm build/*
	- rm src/*.i
	- rm src/*.o
	- rm src/*.s
	- rm *.map
	- rm *.txt 
	- rm testing
	




