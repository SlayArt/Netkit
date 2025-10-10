# Usage:
#   make            # build bin/netkit
#   make -j4        # build parallel
#   make debug      # build with ASAN/UBSAN
#   make clean      # remove obj/ and bin/

SRC_DIR := src
INC_DIR := include
OBJ_DIR := obj
BIN_DIR := bin

CC := gcc
CFLAGS := -Wall -Wextra -I$(INC_DIR) -g -O0
# Generate dependency files (.d)
CFLAGS += -MMD -MP

TARGET := $(BIN_DIR)/netkit

# sources and objects (auto)
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean debug run help

all: $(TARGET)

# Link step
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@printf "\n✅ Built $(TARGET)\n"

# Compile step (pattern rule)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ensure directories exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# include auto-generated dependency files
-include $(OBJS:.o=.d)

# debug build (ASAN/UBSAN)
debug:
	$(MAKE) CFLAGS="-Wall -Wextra -I$(INC_DIR) -g -O0 -fsanitize=address,undefined" all

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
	@printf "🧹 Cleaned build artifacts\n"

run: all
	$(TARGET)

help:
	@echo "Makefile available targets:"
	@echo "  make        -> build $(TARGET)"
	@echo "  make debug  -> build with sanitizers"
	@echo "  make clean  -> remove build artefacts"
	@echo "  make run    -> build and run"
