CXXC = g++

CXXFLAGS = -std=c++11 -O3 -Wall

all:


main: main.cpp main.h
	$(CXX) $(CXXFLAGS) -o main main.h main.cpp -lm

proj: proj.cpp proj.h
	$(CXX) $(CXXFLAGS) -o proj proj.h proj.cpp -lm

proj2: proj2.cpp proj2.h
	$(CXX) $(CXXFLAGS) -o proj2 proj2.h proj2.cpp -lm

v1: v1.cpp proj2.h
	$(CXX) $(CXXFLAGS) -o v1 proj2.h v1.cpp -lm

v2: v2.cpp proj2.h
	$(CXX) $(CXXFLAGS) -o v2 proj2.h v2.cpp -lm

.PHONY: clean
clean:
	rm -f *.o proj

run:
	@./proj

test1:
	@./proj < testes/1.in

test2:
	@./proj < testes/2.in