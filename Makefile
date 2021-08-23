OBJS = main.o Boid.o Flock.o GLScene.o Parameter.o PVector.o
CC = g++
FRAMEWORK = -framework OpenGL -framework GLUT
STD = -std=c++11

all : boid2D clean

boid2D : $(OBJS)
	$(CC) -o boid2D $(OBJS) $(FRAMEWORK) $(STD)
main.o : main.cpp
	$(CC) -c main.cpp
Boid.o : Boid.hpp Boid.cpp
	$(CC) -c Boid.cpp
Flock.o : Flock.hpp Flock.cpp
	$(CC) -c Flock.cpp
GLScene.o : GLScene.hpp GLScene.cpp
	$(CC) -c GLScene.cpp
Parameter.o : Parameter.hpp Parameter.cpp
	$(CC) -c Parameter.cpp
PVector.o : PVector.hpp PVector.cpp
	$(CC) -c PVector.cpp
clean :
	rm *.o