CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC_DIR = src
BIN_DIR = bin

# Automatically find all shared sources
SHARED_SRCS = $(wildcard $(SRC_DIR)/shared/*.c)
SHARED_OBJS = $(patsubst $(SRC_DIR)/shared/%.c, $(BIN_DIR)/shared_%.o, $(SHARED_SRCS))

all:
	@echo "Usage: 'make practice1', 'make practice2', etc."

directories:
	@mkdir -p $(BIN_DIR)

# Pattern rule for shared objects
$(BIN_DIR)/shared_%.o: $(SRC_DIR)/shared/%.c directories
	$(CC) $(CFLAGS) -c $< -o $@

practice%: $(SHARED_OBJS) $(SRC_DIR)/practice%/main.c
	@mkdir -p $(BIN_DIR)/$*
	$(CC) $(CFLAGS) $(SRC_DIR)/practice$*/main.c $(SHARED_OBJS) -o $(BIN_DIR)/$*_exe
	@echo "Build successful. Run: ./$(BIN_DIR)/$*_exe"

clean:
	rm -rf $(BIN_DIR)
