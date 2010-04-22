CC=$(CXX)
CXXFLAGS=-O3 -g `pkg-config --cflags sdl`
LDFLAGS=-O333g `pkg-config --libs sdl`
BINS=test

all: $(BINS)

clean:
	$(RM) $(BINS) *.o

test: test.o simpleSDL.o

