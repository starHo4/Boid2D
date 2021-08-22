#ifndef __Boid__
#define __Boid__

#include "Flock.hpp"
#include "Parameter.hpp"
#include "PVector.hpp"

class Boid
{
private:
    PVector pos;
    PVector dir;
    int id;

public:
    // Constructor //
    Boid(int index, Parameter &P);
    // Getters //
    PVector GetPos();
    PVector GetDir();
    int GetId();
    // Setters //
    void SetPos(double x, double y);
    void SetPos(PVector u);
    void SetDir(double x, double y);
    void SetDir(PVector u);
    void SetId(int val);

    // Function
    void Update();
};

#endif