#ifndef __Parameter__
#define __Parameter__

struct Parameter{
    // For Boids
    static int N;
    static double w_r;  // weight for repulsion
    static double w_a;  // weight for cohesion
    static double w_c;  // weight for alighment

    // For a drawing window
    static int window_width;
    static int window_height;

    static double R;    // Radius of boids' initial position.

};

#endif