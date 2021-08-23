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

double Boid::GetSpeed()
{
    return speed;
}

double Boid::GetRadius()
{
    return radius;
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

void Boid::SetSpeed(double s)
{
    speed = s;
}

void Boid::SetRadius(double r)
{
    radius = r;
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
void Boid::Update(Mat &DistMat, Array &Boids)
{
    PVector rpl = Repulsion(DistMat, Boids);
    PVector ali = Alignment(DistMat, Boids);
    PVector coh = Cohesion(DistMat, Boids);

    dir = ali;
    dir = Add(dir, rpl);
    dir = Add(dir, coh);
    dir = Normalize(dir);
    dir = Mult(dir, speed);
    pos = Add(pos, dir);
}

PVector Boid::Repulsion(Mat &DistMat, Array &Boids)
{
    int N = DistMat.size();
    PVector rpl = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d < radius)
        {
            PVector tmp = Diff(pos, Boids[i].GetPos());
            rpl = Add(rpl, tmp);
        }
    }
    rpl = Normalize(rpl);
    return rpl;
}

PVector Boid::Alignment(Mat &DistMat, Array &Boids)
{
    int N = DistMat.size();
    PVector ali = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d < radius)
        {
            PVector tmp = Boids[i].GetDir();
            ali = Add(ali, tmp);
        }
    }
    ali = Mult(ali, (1 / (N - 1)));
    ali = Normalize(ali);
    PVector steer = Diff(ali, dir);
    return steer;
}

PVector Boid::Cohesion(Mat &DistMat, Array &Boids)
{
    int N = DistMat.size();
    PVector coh = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d < radius)
        {
            PVector tmp = Diff(Boids[id].GetPos(), pos);
            coh = Add(coh, tmp);
        }
    }
    coh = Normalize(coh);
    return coh;
}