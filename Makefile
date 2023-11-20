CXXC = g++

CXXFLAGS = -std=c++11 -O3 -Wall

make:
	$(CXX) $(CXXFLAGS) -o proj2 proj2.h proj2.cpp -lm

clean:
	rm -f *.o proj

run:
	@./proj

test1:
	@./proj < testes/1.in

test2:
	@./proj < testes/2.in