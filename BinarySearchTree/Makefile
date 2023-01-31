BST: main.o BinarySearchTree.o
	g++ -o BST main.o BinarySearchTree.o

main.o: main.cpp BinarySearchTree.h
	g++ -c main.cpp

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -c BinarySearchTree.cpp

clean:
	rm -f BST *.o *~
