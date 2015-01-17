all: test.out


main.o: main.cpp
	g++ -g -c main.cpp -o main.o

Vect.o: Vect.h Vect.cpp
	g++ -g -c Vect.cpp -o Vect.o

Agent.o: Agent.h Agent.cpp
	g++ -g -c Agent.cpp -o Agent.o

Prey.o: Agent.h Prey.h Prey.cpp
	g++ -g -c Prey.cpp -o Prey.o

Predator.o: Agent.h Predator.h Predator.cpp
	g++ -g -c Predator.cpp -o Predator.o

Area.o: Area.h Area.cpp
	g++ -g -c Area.cpp -o  Area.o

bwindow.o: bwindow.cpp bwindow.h
	g++ -g -c bwindow.cpp

test.out: main.o  Vect.o Agent.o Prey.o Predator.o Area.o  bwindow.o
	g++ -g -o test.out main.o  Vect.o Agent.o Prey.o Predator.o Area.o bwindow.o -lX11 -L/usr/X11R6/lib  

clean:
	rm *.o

mrproper: clean
	rm test.out
