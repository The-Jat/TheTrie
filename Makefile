# Compiler
CXX = g++
CC = gcc

# Compiler flags
CXXFLAGS = -Wall -Wextra -std=c++11
CFLAGS = -Wall -Wextra -std=c11

# Source files
CXX_SRCS = main.cpp src/trie.cpp
# CC_SRCS = src/c_file1.c src/c_file2.c

# Object files
CXX_OBJS = $(CXX_SRCS:.cpp=.o)
# CC_OBJS = $(CC_SRCS:.c=.o)

# Include directories
INC_DIRS = -Iheader

# Executable name
EXEC = trie

# Default target
all: $(EXEC)

# Rule to compile C++ source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

# Rule to compile C source files
%.o: %.c
	$(CC) $(CFLAGS) $(INC_DIRS) -c $< -o $@

# Rule to link object files into executable
$(EXEC): $(CXX_OBJS) $(CC_OBJS)
	$(CXX) $(CXXFLAGS) $(CXX_OBJS) $(CC_OBJS) -o $(EXEC)

# Clean target
clean:
	rm -f $(CXX_OBJS) $(CC_OBJS) $(EXEC)
