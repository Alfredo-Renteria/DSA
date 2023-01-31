MinHeap: main.o IntMinHeap.o
	g++ -o MinHeap main.o IntMinHeap.o

main.o: main.cpp IntMinHeap.h
	g++ -c -std=c++11 main.cpp

IntMinHeap.o: IntMinHeap.cpp IntMinHeap.h
	g++ -c -std=c++11 IntMinHeap.cpp

clean:
	rm -f MinHeap *.o *~                                   
