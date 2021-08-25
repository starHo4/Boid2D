#include "Boid.hpp"

// Constructor
Boid::Boid(int index, Parameter &P)
{
    id = index;

    speed = P.Speed;
    r_Rep = P.Radius_rep;
    r_Ali = P.Radius_ali;
    r_Coh = P.Radius_coh;

    w_Rep = P.W_rep;
    w_Ali = P.W_ali;
    w_Coh = P.W_coh;

    size = P.Size;
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

    rpl = Mult(rpl, w_Rep);
    ali = Mult(ali, w_Ali);
    coh = Mult(coh, w_Coh);

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
    int N = Boids.size();
    PVector rpl = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (0 < d && d <= r_Rep)
        {
            PVector tmp = Diff(pos, Boids[i].GetPos());
            tmp = Normalize(tmp);
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
        if (r_Rep < d && d <= r_Ali)
        {
            cnt++;
            PVector tmp = Boids[i].GetDir();
            cout << tmp.x << "  " << tmp.y << endl;
            ali = Add(ali, tmp);
        }
    }
    if (cnt != 0)
    {
        ali = Mult(ali, 1.0 / cnt);
    }
    ali = Normalize(ali);
    PVector steer = Diff(ali, dir);
    steer = Normalize(steer);
    return steer;
}

PVector Boid::Cohesion(Mat &DistMat, Array &Boids)
{
    int N = DistMat.size();
    PVector coh = NullVector();
    for (int i = 0; i < N; i++)
    {
        double d = DistMat[id][i];
        if (r_Ali < d && d <= r_Coh)
        {
            PVector tmp = Diff(Boids[i].GetPos(), pos);
            tmp = Normalize(tmp);
            coh = Add(coh, tmp);
        }
    }
    coh = Normalize(coh);
    return coh;
}