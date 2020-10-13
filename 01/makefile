all: alloc
alloc: allocator.o test.o
	g++ -std=c++17 allocator.o test.o -o t
allocator.o: allocator.cpp allocator.hpp
	g++ -std=c++17 -c allocator.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o alloc t
test:
	./t