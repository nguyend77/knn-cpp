CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/knn

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)