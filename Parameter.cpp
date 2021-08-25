#include "Parameter.hpp"

mt19937_64 Parameter::mt(Parameter::RANDOM_SEED);

int Parameter::N = 50;
double Parameter::Size = 15.0;
double Parameter::Speed = 3.0;
double Parameter::Radius_rep = 10.0;
double Parameter::Radius_ali = 30.0;
double Parameter::Radius_coh = 10.0;
double Parameter::W_rep = 1.5;
double Parameter::W_ali = 1;
double Parameter::W_coh = 1;

int Parameter::window_width = 1200;
int Parameter::window_height = 794;

double Parameter::R = 100;