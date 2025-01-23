# Compiler, compilation flags and libraries
CC = g++
CFLAGS = -O2
LIBS = 

# Get current working directory (for valgrind)
DIR = $(shell pwd)

.PHONY: all clean			# Note targets which do not depend on any files

all: compile run

main: application.cpp neuron.cpp layer.cpp model.cpp
	@$(CC) $(CFLAGS) application.cpp neuron.cpp layer.cpp model.cpp -o app.out $(LIBS)
	@./app.out

compile: application.cpp neuron.cpp layer.cpp model.cpp
	@$(CC) $(CFLAGS) application.cpp neuron.cpp layer.cpp model.cpp -o app.out $(LIBS)

run: app.out
	@./app.out

clean:
ifeq ($(OS),Windows_NT)
	del /Q *.o *.out *.exe
else
	rm -rf *.o *.out *.exe
endif