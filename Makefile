CC=g++

CFLAGS=-Wall -Werror -O3 -I./include -std=c++23

LD_FLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC=./src
OBJ=./obj
BIN=./bin

SOURCES=$(wildcard $(SRC)/*.cc)
OBJECTS=$(patsubst $(SRC)/%.cc, $(OBJ)/%.o, $(SOURCES))

EXECUTABLE=$(BIN)/Tetris

.PHONY: all clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LD_FLAGS)

$(OBJ)/%.o: $(SRC)/%.cc
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)/*.o $(BIN)/* 