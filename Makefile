CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -Iinclude

all: test clean run

test: main.o number.o
	$(CXX) $(CXXFLAGS) main.o number.o -o test

main.o:
	$(CXX) $(CXXFLAGS) -c main.cpp

number.o:
	$(CXX) $(CXXFLAGS) -c src/number.cpp

.PHONY: clean run

run:
	./test
clean:
	rm -rf *.o