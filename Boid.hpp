#ifndef __Boid__
#define __Boid__

#include "PVector.hpp"

class Boid
{
private:
    PVector pos;
    PVector dir;
    int id;

public:
    // Constructor //
    Boid(int index);
    // Getters //
    PVector GetPos();
    PVector GetDir();
    int GetId();
    // Setters //
    void SetPos(double x, double y);
    void SetPos(PVector u);
    void SetDir(double x, double y);
    void SetDir(PVector u);

    // Function
    void Update();
};

#endif