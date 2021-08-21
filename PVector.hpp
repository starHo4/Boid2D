#ifndef __PVector__
#define __PVector__

#include <cmath>

typedef struct
{
    double x, y;
} PVector;

PVector Add(PVector u, PVector v);

PVector Diff(PVector u, PVector v);

PVector Mult(PVector u, double a);

double Dot(PVector u, PVector v);

double Norm(PVector u);

PVector Normalize(PVector u);

double Dist(PVector u, PVector v);

PVector NullVector();

PVector NewVec(double x, double y);

#endif