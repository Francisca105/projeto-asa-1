CXXC = g++

CXXFLAGS = -std=c++11 -O3 -Wall

all: main proj proj2 v1 v2 v3 v4 v5

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

v3: v3.cpp
	$(CXX) $(CXXFLAGS) -o v3 v3.cpp -lm

v4: v4.cpp
	$(CXX) $(CXXFLAGS) -o v4 v4.cpp -lm

v5: v5.cpp
	$(CXX) $(CXXFLAGS) -o v5 v5.cpp -lm

.PHONY: clean
clean:
	rm -f main proj proj2 v1 v2 v3 v4

run:
	@./proj

test1:
	@./proj < testes/1.in

test2:
	@./proj < testes/2.in