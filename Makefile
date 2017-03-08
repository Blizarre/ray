CXX=clang++
CXXFLAGS=-O3 -std=c++11 `pkg-config --cflags sdl2` -Wall -Wextra
LDFLAGS=-O3 `pkg-config --libs sdl2` -Wall -Wextra

BIN=main

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)


all: $(BIN)

clean:
	$(RM) $(BIN) *.o

$(BIN): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(BIN)

