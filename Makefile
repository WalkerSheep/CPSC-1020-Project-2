// Defines compiler to use, compiler options, and name to execute
COMPILER = g++
OPTIONS = -Wall -std=c++11
PROGRAM = Project2

// Build and runs the targets
all: $(PROGRAM)
run: $(PROGRAM)
	./$(PROGRAM)

// Compiles source files
$(PROGRAM): P2G1test.cpp cafe.cpp customer.cpp
	$(COMPILER) $(OPTIONS) P2G1test.cpp cafe.cpp customer.cpp -o $(PROGRAM)

// Remove compile files and cleans up the directory
clean:
	rm -f $(PROGRAM)
