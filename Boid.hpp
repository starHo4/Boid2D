#ifndef __Boid__
#define __Boid__

#include <random>
#include "PVector.hpp"
using namespace std;

class Boid
{
private:
    PVector pos;
    PVector dir;
    double angle;
    double size;
    int id;

public:
    // Constructor //
    Boid(int index);
    // Getters //
    PVector GetPos();
    PVector GetDir();
    double GetAngle();
    double GetSize();
    int GetId();
    // Setters //
    void SetPos(double x, double y);
    void SetPos(PVector u);
    void SetDir(double x, double y);
    void SetDir(PVector u);
    void SetAngle(double a);
    void SetSize(double s);
    void SetId(int val);

    // Function
    void Update();
};

#endif