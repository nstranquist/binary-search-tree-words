# Makefile

main: main.o tree.o
	g++ main.o tree.o -o main

main.o: main.cpp tree.h node.h
	g++ -c -Wall main.cpp

tree.o: tree.cpp tree.h node.h
	g++ -c -Wall tree.cpp