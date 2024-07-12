# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11

# Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
OBJ_DIR = obj

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS = $(wildcard $(INC_DIR)/*.h)

# Executable
TARGET = $(BUILD_DIR)/space_invaders

# Build target
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

# Object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR)/* $(BUILD_DIR)/*

# Phony targets
.PHONY: clean
