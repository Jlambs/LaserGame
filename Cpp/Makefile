CXX = g++
CXXFLAGS	= -std=c++17 -Wall

all: game

clean:
	rm LaserGame.o game

game: LaserGame.o main.cpp
	$(CXX) $(CXXFLAGS) main.cpp LaserGame.o -o game

LaserGame.o: LaserGame.cpp LaserGame.h
	$(CXX) $(CXXFLAGS) -c LaserGame.cpp
