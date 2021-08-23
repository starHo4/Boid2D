#ifndef __Boid__
#define __Boid__

#include <iostream>
#include <random>
#include "Flock.hpp"
#include "PVector.hpp"
using namespace std;

class Boid;

typedef vector<Boid> Array;
typedef vector<vector<double>> Mat;

class Boid
{
private:
    PVector pos;
    PVector dir;
    double angle;
    double speed;
    double radius;
    double size;
    int id;

public:
    // Constructor //
    Boid(int index);
    // Getters //
    PVector GetPos();
    PVector GetDir();
    double GetAngle();
    double GetSpeed();
    double GetRadius();
    double GetSize();
    int GetId();
    // Setters //
    void SetPos(double x, double y);
    void SetPos(PVector u);
    void SetDir(double x, double y);
    void SetDir(PVector u);
    void SetAngle(double a);
    void SetSpeed(double s);
    void SetRadius(double r);
    void SetSize(double s);
    void SetId(int val);

    // Function
    void Update(Mat &DistMat, Array &Boids);
    PVector Repulsion(Mat &DistMat, Array &Boids);
    PVector Alignment(Mat &DistMat, Array &Boids);
    PVector Cohesion(Mat &DistMat, Array &Boids);
};

#endif