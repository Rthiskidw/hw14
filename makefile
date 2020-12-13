CC = g++
FLAGS = -std=c++14 -Wall -g
OBJS = hw14.o 

all: hw14

hw14: hw14.cpp
	$(CC) $(FLAGS) hw14.cpp -o hw14 

clean:
	rm *.o hw14 hw14.tar

tar:
	tar cf hw14.tar hw14.scr makefile hw14.cpp doublyList.h
