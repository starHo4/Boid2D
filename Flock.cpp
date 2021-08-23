#include "Flock.hpp"

// Constructor
Flock::Flock(Parameter &P)
{
    Size = P.N;
    Boids = Array(Size, Boid(0));
    for (int i = 0; i < Size; i++)
    {
        // Set id of each boid.
        Boids[i].SetId(i);
        // Set size of each boid.
        Boids[i].SetSize(P.Size);
        // Set position of each boid.
        uniform_real_distribution<double> udd_R(-P.R, P.R);
        Boids[i].SetPos(udd_R(P.mt), udd_R(P.mt));
        // Set direction of each boid.
        uniform_real_distribution<double> udd_PI(-PI, PI);
        double a = udd_PI(P.mt);
        Boids[i].SetAngle(a);
        Boids[i].SetDir(cos(a), sin(a));
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