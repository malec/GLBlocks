# define libraries
LIB = -lGL -lGLU -lglut

# define g++ flags
CC = g++

project2: project2.cpp
	$(CC) -o project2 project2.cpp $(LIB)