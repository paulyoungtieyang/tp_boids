all: test.out



main.o: main.cpp
	g++ -g -c main.cpp -o main.o

Agent.o: Agent.h Agent.cpp
	g++ -g -c Agent.cpp -o Agent.o

Vect.o: Vect.h Vect.cpp
	g++ -g -c Vect.cpp -o Vect.o

test.out: main.o Agent.o Vect.o
	g++ -g main.o Agent.o Vect.o -o test.out

clean:
	rm *.o

mrproper: clean
	rm test.out
