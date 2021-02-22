# Makefile

main: main.o tree.o node.o
	g++ main.o tree.o node.o -o main

main.o: main.cpp tree.h node.h
	g++ -c -Wall main.cpp

tree.o: tree.cpp tree.h node.h
	g++ -c -Wall tree.cpp

node.o: node.cpp node.h
	g++ -c -Wall node.cpp