CXX=clang++
CXXFLAGS=-O3 -std=c++11 `pkg-config --cflags sdl2` -Wall -Wextra
LDFLAGS=-O3 `pkg-config --libs sdl2` -Wall -Wextra

BIN=main

SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

# http://scottmcpeak.com/autodepend/autodepend.html
-include $(OBJECTS:.o=.d)


%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $*.cpp -o $*.o
	$(CXX) -MM $(CXXFLAGS) $*.cpp > $*.d

all: $(BIN)

clean:
	$(RM) $(BIN) *.o *.d

$(BIN): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) -o $(BIN)

