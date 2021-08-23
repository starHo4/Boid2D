#include "Parameter.hpp"

mt19937_64 Parameter::mt(Parameter::RANDOM_SEED);

int Parameter::N = 30;
double Parameter::Size = 5.0;
double Parameter::W_r = 1;
double Parameter::W_a = 1;
double Parameter::W_c = 1;

int Parameter::window_width = 794;
int Parameter::window_height = 794;

double Parameter::R = 200;