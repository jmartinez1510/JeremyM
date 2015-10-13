CFLAGS = -I ./include
#LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr

all: jsman

jsman: jsman.cpp
	g++ $(CFlags) jsman.cpp libggfonts.a -Wall -ojsman -lX11 -lGL -lGLU -lm

clean:
	rm -f jsman
	rm -f *.o

