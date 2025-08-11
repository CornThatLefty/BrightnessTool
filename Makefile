CC = g++
CFLAGS = -Wall -std=c++11

SRC_DIR = src
BIN_DIR = bin

SRC = $(SRC_DIR)/brightness.cpp
OUT = $(BIN_DIR)/brightness-tool

all: $(OUT)

$(OUT): $(SRC)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

# Clean target
clean:
	rm -rf $(BIN_DIR)
