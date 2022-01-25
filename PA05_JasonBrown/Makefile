proj5_OUTPUT: proj5.o BinaryNode.o BinarySearchTree.o 
	g++ proj5.o BinaryNode.o BinarySearchTree.o -o proj5_OUTPUT

BinaryNode.o: src/BinaryNode/BinaryNode.h src/BinaryNode/BinaryNode.cpp
	g++ -c src/BinaryNode/BinaryNode.cpp

BinarySearchTree.o: src/BinarySearchTree/BinarySearchTree.h src/BinarySearchTree/BinarySearchTree.cpp
	g++ -c src/BinarySearchTree/BinarySearchTree.cpp

proj5.o: proj5.cpp
	g++ -c proj5.cpp

clean:
	rm *.o 