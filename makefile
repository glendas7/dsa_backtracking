all: PrepBoat
PrepBoat: main.o Boat.o
	g++ -o prep main.o Boat.o
main.o: main.cpp
	g++ -c -g main.cpp
Boat.o: Boat.cpp
	g++ -c -g Boat.cpp
