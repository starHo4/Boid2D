#ifndef __Flock__
#define __Flock__

#include <list>
#include <vector>
#include "Boid.hpp"
using namespace std;

typedef list<Boid> List;
typedef List::iterator Itr;
typedef vector<vector<double>> Mat;

class Flock
{
private:
    Itr Itr_b;
    List Boids;
    int Size;

public:
    // Matrix of Distance.
    Mat MatDist;

    // Constructor
    Flock();
    // Getters
    Itr GetItr();
    List GetBoids();
    int GetSize();

    // Function
    void Update();
    void CalcDistMat();
}

#endif