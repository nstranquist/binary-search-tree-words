# Variables
# GCC = gcc
# CFLAGS = -Wall
# DEPS = tree.h tree.c node.h
# OBJ = tree.o

# # Targets
# %.o: %.c $(DEPS)
# 	$(CC) $(CFLAGS) -c -o $@ $<

# doMath: $(OBJ)
# 	gcc $(CFLAGS) -o $@ $^

CC = g++
CFLAGS = -Wall -g

# Targets
main: main.o tree.o
	$(CC) $(CFLAGS) -o main main.o tree.o

main.o: main.cpp tree.h node.h
	$(CC) $(CFLAGS) -c main.cpp

tree.o: tree.cpp tree.h

# node.o: node.h

 # the compiler: gcc for C program, define as g++ for C++
# CC = gcc

# # compiler flags:
# #  -g    adds debugging information to the executable file
# #  -Wall turns on most, but not all, compiler warnings
# CFLAGS  = -g -Wall

# # the build target executable:
# TARGET = main

# all: $(TARGET)

# $(TARGET): $(TARGET).c
# 	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

# clean:
# 	$(RM) $(TARGET)