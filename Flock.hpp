#ifndef __Flock__
#define __Flock__

#include <cmath>
#include <vector>
#include "Boid.hpp"
#include "Parameter.hpp"
using namespace std;

#define PI M_PI

class Boid;

typedef vector<Boid> Array;
typedef Array::iterator Itr;
typedef vector<vector<double>> Mat;

class Flock
{
private:
    Itr Itr_b;
    Array Boids;
    int Size;

public:
    // Matrix of Distance.
    Mat DistMat;

    // Constructor
    Flock(Parameter &P);
    // Getters
    Itr GetItr();
    Array GetBoids();
    int GetSize();

    // Function
    void Update();
    void CalcDistMat();
};

#endif