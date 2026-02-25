CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g

SRC_DIR = src
BIN_DIR = bin

# En Windows usamos contra barra para rutas si es necesario, 
# aunque GCC acepta / usualmente.
SHARED_SRCS = $(wildcard $(SRC_DIR)/shared/*.c)
SHARED_OBJS = $(patsubst $(SRC_DIR)/shared/%.c, $(BIN_DIR)/shared_%.o, $(SHARED_SRCS))

all:
	@echo Usage: "make practice1", "make practice2", etc.

# Crear directorios en Windows (verificando si existen para no dar error)
directories:
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	@if not exist $(BIN_DIR)\shared mkdir $(BIN_DIR)\shared

$(BIN_DIR)/shared_%.o: $(SRC_DIR)/shared/%.c directories
	$(CC) $(CFLAGS) -c $< -o $@

practice%: $(SHARED_OBJS) $(SRC_DIR)/practice%/main.c
	@if not exist $(BIN_DIR)\$* mkdir $(BIN_DIR)\$*
	$(CC) $(CFLAGS) $(SRC_DIR)/practice$*/main.c $(SHARED_OBJS) -o $(BIN_DIR)/$*/main.exe
	@echo Build successful. Run: $(BIN_DIR)\$*\main.exe

clean:
	@if exist $(BIN_DIR) rd /s /q $(BIN_DIR)