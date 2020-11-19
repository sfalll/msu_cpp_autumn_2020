all: format
format: test.o matrix.o
	g++ -std=c++17 test.o matrix.o -o t
matrix.o: matrix.cpp matrix.hpp
	g++ -std=c++17 -c matrix.cpp
test.o: test.cpp format.hpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o format t
test:
	./t