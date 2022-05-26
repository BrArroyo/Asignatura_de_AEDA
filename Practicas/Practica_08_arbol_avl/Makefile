# Makefile 

make: include/NodoAVL.h include/AVL.h include/AB.h include/ABE.h include/ABB.h include/NodoB.h src/main.cc
	g++ -std=c++11 src/main.cc -o avl

debug: include/NodoAVL.h include/AVL.h include/AB.h include/ABE.h include/ABB.h include/NodoB.h src/main.cc
	g++ -D DEBUG -std=c++11 src/main.cc -o avl	

clean:
	rm -f .out avl	