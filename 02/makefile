all: parse
parse: parser.o test.o
	g++ -std=c++17 parser.o test.o -o t
parser.o: parser.cpp parser.hpp
	g++ -std=c++17 -c parser.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o parse t
test:
	./t