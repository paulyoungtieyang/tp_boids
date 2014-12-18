all: test.out



main.o: main.cpp
	g++ -g -c main.cpp -o main.o

Agent.o: Agent.h Agent.cpp
	g++ -g -c Agent.cpp -o Agent.o

Vect.o: Vect.h Vect.cpp
	g++ -g -c Vect.cpp -o Vect.o

Area.o: Area.h Area.cpp
	g++ -g -c Area.cpp -o Area.o

test.out: main.o Agent.o Vect.o Area.o
	g++ -g main.o Agent.o Vect.o Area.o  -o test.out

clean:
	rm *.o

mrproper: clean
	rm test.out
