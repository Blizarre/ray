CC=$(CXX)
CXXFLAGS= -g `pkg-config --cflags sdl` -Wall
LDFLAGS=-g `pkg-config --libs sdl` -Wall
BINS=test

all: $(BINS)

clean:
	$(RM) $(BINS) *.o

test: test.o simpleSDL.o element.o sphere.o

