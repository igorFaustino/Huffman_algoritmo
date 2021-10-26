CC			:= g++

BIN			:= bin
INCLUDE		:= include
SRC			:= src

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= huff.exe
else
EXECUTABLE	:= huff
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*
	mkdir -p $(BIN)/
	$(CC)  -I $(INCLUDE) $^ -o $@
