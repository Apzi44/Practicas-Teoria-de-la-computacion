CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC_DIR = src
BIN_DIR = bin

SHARED_SRC = $(SRC_DIR)/shared/theory.c
SHARED_OBJ = $(BIN_DIR)/shared_theory.o

all:
	@echo "Usage: 'make practice1', 'make practice2', etc."

directories:
	@mkdir -p $(BIN_DIR)

$(SHARED_OBJ): $(SHARED_SRC) directories
	$(CC) $(CFLAGS) -c $(SHARED_SRC) -o $(SHARED_OBJ)

practice%: $(SHARED_OBJ) $(SRC_DIR)/practice%/main.c
	@mkdir -p $(BIN_DIR)/$*
	$(CC) $(CFLAGS) $(SRC_DIR)/practice$*/main.c $(SHARED_OBJ) -o $(BIN_DIR)/practice$*_exe
	@echo "Build successful. Run: ./$(BIN_DIR)/practice$*_exe"

clean:
	rm -rf $(BIN_DIR)
