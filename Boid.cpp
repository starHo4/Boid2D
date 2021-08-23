#include "Boid.hpp"

// Constructor
Boid::Boid(int index)
{
    id = index;
}

// Getters
PVector Boid::GetPos()
{
    return pos;
}

PVector Boid::GetDir()
{
    return dir;
}

double Boid::GetAngle()
{
    return angle;
}

double Boid::GetSize()
{
    return size;
}

int Boid::GetId()
{
    return id;
}

// Setters
void Boid::SetPos(double x, double y)
{
    pos = NewVec(x, y);
}

void Boid::SetPos(PVector u)
{
    pos = u;
}

void Boid::SetDir(double x, double y)
{
    dir = NewVec(x, y);
}

void Boid::SetDir(PVector u)
{
    dir = u;
}

void Boid::SetAngle(double a)
{
    angle = a;
}

void Boid::SetSize(double s)
{
    size = s;
}

void Boid::SetId(int val)
{
    id = val;
}

// Function
void Boid::Update()
{
    pos = Add(pos, dir);
}