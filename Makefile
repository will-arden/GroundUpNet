# Compiler, compilation flags and libraries
CC = g++
CFLAGS = -O2
LIBS = 

# Get current working directory (for valgrind)
DIR = $(shell pwd)

.PHONY: all clean			# Note targets which do not depend on any files

all: compile run

main: application.cpp neuron.cpp
	@$(CC) $(CFLAGS) application.cpp neuron.cpp -o app.out $(LIBS)
	@./app.out

compile: application.cpp neuron.cpp
	@$(CC) $(CFLAGS) application.cpp neuron.cpp -o app.out $(LIBS)

run: app.out
	@./app.out

clean:
	rm -rf *.o *.out callgrind.out*