CPPFLAGS=-std=c++11

all: main

main: FloydWarshall.hpp Matrix.hpp Tropical.hpp

clean:
	rm main
