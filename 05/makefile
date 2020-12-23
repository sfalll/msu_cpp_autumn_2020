all: serializer
serializer: serializer.o deserializer.o test.o
	g++ -std=c++17 serializer.o deserializer.o test.o -o t
serializer.o: serializer.cpp serializer.hpp	
	g++ -std=c++17 -c serializer.cpp
deserializer.o: deserializer.cpp deserializer.hpp serializer.hpp
	g++ -std=c++17 -c deserializer.cpp
test.o: test.cpp
	g++ -std=c++17 -c test.cpp
clean:
	rm -rf *.o t
test:
	./t