all: pool
pool: pool.o test.o
	g++ -std=c++17 pool.o test.o -o t -lpthread
pool.o: pool.cpp pool.hpp
	g++ -std=c++17 -c pool.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o t
test:
	./t