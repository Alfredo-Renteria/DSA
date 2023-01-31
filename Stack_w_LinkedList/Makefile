StackLL: main.o Stack.o
	g++ -o StackLL main.o Stack.o

main.o: main.cpp Stack.h
	g++ -c main.cpp

Stack.o: Stack.cpp Stack.h LinkList.h
	g++ -c Stack.cpp

clean:
	rm -f StackLL *.o *~