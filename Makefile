CC=$(CXX)
CXXFLAGS=-O3 -g `pkg-config --cflags sdl` -fopenmp -Wall
LDFLAGS=-O3 -g `pkg-config --libs sdl ` -fopenmp -Wall
BINS=test

all: $(BINS)

clean:
	$(RM) $(BINS) *.o

test: test.o simpleSDL.o

