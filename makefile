all: Maze
Maze: main.o Boat.o
	g++ -o prepcargo main.o Boat.o
main.o: main.cpp
	g++ -c -g main.cpp
Boat.o: Boat.cpp
	g++ -c -g Boat.cpp
