all: test.out



main.o: main.cpp
	g++ -g -c main.cpp -o main.o

Agent.o: Agent.h Agent.cpp
	g++ -g -c Agent.cpp -o Agent.o

test.out: main.o Agent.o
	g++ -g main.o Agent.o -o test.out

clean:
	rm *.o

mrproper: clean
	rm test.out
