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
    PVector new_dir = NullVector();

    PVector rpl = Repulsion(DistMat, Boids);
    PVector ali = Alignment(DistMat, Boids);
    PVector coh = Cohesion(DistMat, Boids);

    // if (id == 0)
    // {
    //     cout << rpl.x << " " << rpl.y << endl;
    //     cout << ali.x << " " << ali.y << endl;
    //     cout << coh.x << " " << coh.y << endl;
    //     cout << endl;
    // }

    new_dir = Add(dir, rpl);
    new_dir = Add(dir, ali);
    new_dir = Add(dir, coh);
    new_dir = Normalize(new_dir);
    dir = new_dir;
    PVector tmp = Mult(dir, speed);
    pos = Add(pos, tmp);
}

PVector Boid::Repulsion(Mat &DistMat, Array &Boids)
{
    int N = DistMat.size();
    PVector rpl = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d < 10.0)
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
    int cnt = 0;
    PVector ali = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d < radius)
        {
            cnt++;
            PVector tmp = Boids[i].GetDir();
            ali = Add(ali, tmp);
        }
    }
    if (cnt != 0)
    {
        ali = Mult(ali, 1.0 / cnt);
    }
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
        if (0 < d && d < 30.0)
        {
            PVector tmp = Diff(Boids[i].GetPos(), pos);
            coh = Add(coh, tmp);
        }
    }
    coh = Normalize(coh);
    return coh;
}