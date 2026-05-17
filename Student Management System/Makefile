# Makefile for Student Management System

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Target executable
TARGET = student_system

# Source file
SRC = student_management_system.cpp

# Default target
all: $(TARGET)

# Compile the program
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	@echo "✓ Compilation successful!"
	@echo "Run with: ./$(TARGET)"

# Clean build files
clean:
	rm -f $(TARGET)
	@echo "✓ Cleaned build files"

# Clean all (including data file)
clean-all: clean
	rm -f students.txt
	@echo "✓ Cleaned all files including data"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS = -std=c++11 -Wall -Wextra -g -DDEBUG
debug: $(TARGET)
	@echo "✓ Debug build complete"

# Help
help:
	@echo "Student Management System - Makefile Commands"
	@echo "=============================================="
	@echo "make          - Compile the program"
	@echo "make run      - Compile and run"
	@echo "make clean    - Remove executable"
	@echo "make clean-all- Remove executable and data file"
	@echo "make debug    - Compile with debug symbols"
	@echo "make help     - Show this help message"

.PHONY: all clean clean-all run debug help
