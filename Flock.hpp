#ifndef __Flock__
#define __Flock__

#include <list>
#include "Boid.hpp"
using namespace std;

typedef list<Boid> List;
typedef List::iterator Itr;

class Flock
{
private:
    Itr Itr_b;
    List Boids;
    int Size;

public:
    // Constructor
    Flock();
    // Getters
    Itr GetItr();
    List GetBoids();
    int GetSize();

    // Function
    void Update();
}

#endif