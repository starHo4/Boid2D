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

void Boid::Update(){
    
}