SRC:=source
INC:=include
BUILD:=build
CFLAG:=-c -Wall  -g
LFLAG:= -Xlinker -Map=main.map -g



$(BUILD)/main.o:$(SRC)/main.c 
	gcc $(CFLAG) $(SRC)/main.c -o $(BUILD)/main.o -I$(INC)/ 

$(BUILD)/someone.o:$(SRC)/someone.c 
	gcc $(CFLAG) $(SRC)/someone.c -o $(BUILD)/someone.o -I$(INC)/ 

all: $(BUILD)/main.o $(BUILD)/someone.o
	gcc $(LFLAG)  $^ -o main 
	size main

debug: all
	gdb main

excecute: all
	./main


clean:
	rm build/*.o
	rm main
	rm *.txt