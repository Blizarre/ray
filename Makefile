CXX=clang++
CXXFLAGS=-O3 -std=c++11 `pkg-config --cflags sdl2` -Wall -Wextra
LDFLAGS=-O3 `pkg-config --libs sdl2` -Wall -Wextra

BINS=test

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


all: $(BINS)

clean:
	$(RM) $(BINS) *.o

test: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o test

