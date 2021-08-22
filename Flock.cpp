#include "Flock.hpp"

// Constructor
Flock::Flock(Parameter &P)
{
    Size = P.N;
    Boids = Array(Size, Boids(0, P));
    for (int i = 0; i < Size; i++)
    {
        Boids[i].SetId(i);
    }
    DistMat = Mat(Size, vector<double>(Size, 0));
}

// Getters
Itr Flock::GetItr()
{
    return Itr_b;
}

Array Flock::GetBoids()
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

void Flock::CalcDistMat()
{
    for (int i = 0; i < Size; i++)
    {
        for (int j = i + 1; j < Size; j++)
        {
            DistMat[i][j] = Dist(Boids[i].GetPos(), Boids[j].GetPos());
        }
    }
}