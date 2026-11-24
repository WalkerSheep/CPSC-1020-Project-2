# Compiler and program
COMPILER = g++
OPTIONS = -Wall -std=c++11
PROGRAM = Project2

all: $(PROGRAM)

# Compile the simulation
$(PROGRAM): P2G1main.cpp Cafe.cpp Customer.cpp Cafe.h Customer.h
	$(COMPILER) $(OPTIONS) P2G1main.cpp Cafe.cpp Customer.cpp -o $(PROGRAM)

# Run program
run: $(PROGRAM)
	./$(PROGRAM)

# Clean program
clean:
	rm -f $(PROGRAM)