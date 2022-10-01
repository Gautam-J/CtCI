BIN=./bin
SRC=./src
CC=g++
CFLAGS=-std=c++17 -fsanitize=address -fsanitize=undefined -Wall -Wshadow -Wno-unused-result -D_GLIBCXX_DEBUG -O2

SOURCES = $(wildcard $(SRC)/*.cpp)
EXECS = $(patsubst $(SRC)/%.cpp,$(BIN)/%,$(SOURCES))

all: $(EXECS)

$(BIN)/%:  $(SRC)/%.cpp
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) $(INC) $< -o $@ $(LIBS)
