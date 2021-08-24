#include "Parameter.hpp"

mt19937_64 Parameter::mt(Parameter::RANDOM_SEED);

int Parameter::N = 50;
double Parameter::Size = 15.0;
double Parameter::Speed = 3.0;
double Parameter::Radius = 25.0;
double Parameter::W_r = 1;
double Parameter::W_a = 1;
double Parameter::W_c = 1;

int Parameter::window_width = 1200;
int Parameter::window_height = 794;

double Parameter::R = 100;