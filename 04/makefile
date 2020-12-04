all: big
big: big.o test.o
	g++ -std=c++17 big.o test.o -o t
big.o: big.cpp big.hpp
	g++ -std=c++17 -c big.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o big t
test:
	./t