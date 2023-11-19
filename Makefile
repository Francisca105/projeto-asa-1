CXXC = g++

CXXFLAGS = -std=c++11 -O3 -Wall

make:
	$(CXX) $(CXXFLAGS) -o proj proj.h proj.cpp -lm

clean:
	rm -f *.o proj

run:
	@./proj