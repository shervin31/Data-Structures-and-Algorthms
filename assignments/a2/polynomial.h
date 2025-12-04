#ifndef POLYNOMIAL_C
#define POLYNOMIAL_C

float horner(float *p, int n, float x);
void derivative(float *p, float *d, int n);
float newton(float *p, int n, float x0);

#endif