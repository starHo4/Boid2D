OBJS = main.o GLScene.o PVector.o
CC = g++
FRAMEWORK = -framework OpenGL -framework GLUT
STD = -std=c++11

all : boid2D clean

boid2D : $(OBJS)
	$(CC) -o boid2D $(OBJS) $(FRAMEWORK) $(STD)
main.o : main.cpp
	$(CC) -c main.cpp
GLScene.o : GLScene.hpp GLScene.cpp
	$(CC) -c GLScene.cpp
PVector.o : PVector.hpp PVector.cpp
	$(CC) -c PVector.cpp
clean :
	rm *.o