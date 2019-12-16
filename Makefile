CC		:= g++
C_FLAGS := -std=c++17 -Wall -Wextra -g

BIN		:= bin
SRC		:= src
INCLUDE	:= include -L lib -l SDL2-2.0.0
LIB		:= lib

LIBRARIES	:=

ifeq ($(OS),Windows_NT)
EXECUTABLE	:= main.exe
else
EXECUTABLE	:= main
endif

all: $(BIN)/$(EXECUTABLE)

clean:
	$(RM) $(BIN)/$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CC) $(C_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)