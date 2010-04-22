CC=$(CXX)
CXXFLAGS=-O3 -g `pkg-config --cflags sdl`
BINS=test
LDCXX=g++
LDFLAGS=-O3 -g `pkg-config --libs sdl`

all: $(BINS)

clean:
	$(RM) $(BINS) *.o

test: test.o simpleSDL.o

