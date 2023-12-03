CXXC = gcc
CXXFLAGS = -std=c11 -O3 -Wall
FILE=proj

all: main

main: projeto.c
	$(CXX) $(CXXFLAGS) -o $(FILE) projeto.c -lm

.PHONY: clean
clean:
	rm -f $(FILE)

run:
	@./proj