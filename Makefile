WFLAGS=-Wall -Werror -ansi -pedantic
PP=g++
STD=-std=c++0x
SFMLIB=-lsfml-graphics -lsfml-system -lsfml-window

all: NBody

NBody: main.o Body.o
	$(PP) $(STD) $(WFLAGS) -o NBody main.o Body.o $(SFMLIB)

main.o: main.cpp Body.o
	$(PP) $(STD) $(WFLAGS) -c main.cpp

Body.o: Body.cpp Body.hpp
	$(PP) $(STD) $(WFLAGS) -c Body.cpp

clean:
	rm *.o NBody
