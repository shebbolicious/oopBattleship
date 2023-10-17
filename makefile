# Makefile

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra

# Executable name
TARGET = run

# Source files
SRCS = main.cpp grid.cpp LShapedShip.cpp Missile.cpp ship.cpp StealthShip.cpp StraightShip.cpp MainMenu.cpp

# Build and run tests
.PHONY: all
all:
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	./$(TARGET)

# Clean rule
.PHONY: clean
clean:
	rm -f $(TARGET)
