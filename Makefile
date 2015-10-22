CFLAGS = -I ./include
#LFLAGS = -lrt -lX11 -lGLU -lGL -pthread -lm #-lXrandr

all: jeremyM

jeremyM: jeremyM.cpp
	g++ $(CFlags) jeremyM.cpp libggfonts.a -Wall -ojeremyM -lX11 -lGL -lGLU -lm

clean:
	rm -f jeremyM
	rm -f *.o

