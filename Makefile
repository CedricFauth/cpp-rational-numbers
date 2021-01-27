CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -Iinclude

all: test clean run

test: main.o qnumber.o
	$(CXX) $(CXXFLAGS) main.o qnumber.o -o test

main.o:
	$(CXX) $(CXXFLAGS) -c src/main.cpp

qnumber.o:
	$(CXX) $(CXXFLAGS) -c src/qnumber.cpp

.PHONY: clean run

run:
	./test
clean:
	rm -rf *.o