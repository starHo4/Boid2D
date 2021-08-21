#include "Flock.hpp"

// Constructor
Flock::Flock()
{
}

// Getters
Itr Flock::GetItr()
{
    return Itr_b;
}

List Flock::GetBoids()
{
    return Boids;
}

int Flock::GetSize()
{
    return Size;
}

void Flock::Update()
{
    for (Itr_b = Boids.begin(); Itr_b != Boids.end(); Itr_b++)
    {
        Boid *boid = &(*Itr_b);
        boid->Update();
    }
}

void Flock::CalcDistMat(){

}