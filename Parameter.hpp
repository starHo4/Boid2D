#ifndef __Parameter__
#define __Parameter__

#include <random>
using namespace std;

struct Parameter{
    // For a random generator
    static const int RANDOM_SEED = 0;
    static mt19937_64 mt;
    
    // For Boids
    static int N;
    static double Size;
    static double Speed;
    static double Radius;
    static double W_r;  // weight for repulsion
    static double W_a;  // weight for cohesion
    static double W_c;  // weight for alighment

    // For a drawing window
    static int window_width;
    static int window_height;

    static double R;    // Radius of boids' initial position.

};

#endif