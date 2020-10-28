all: matrix
matrix: matrix.o test.o
	g++ -std=c++17 matrix.o test.o -o t
matrix.o: matrix.cpp matrix.hpp
	g++ -std=c++17 -c matrix.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o matrix t
test:
	./t