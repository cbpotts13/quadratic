//Quadratic Solver
#include <math.h>
#include "quad.h"


int solve_quad(Values *val, Roots *roots) {
double a,b,c;  // coefs of quadratic , LOCAL COPIES 
double d;      // discriminate d = b^2 = 4ac
double sqrtd; // sqrt of d;


a = val->a;
b = val->b;
c = val->c;

if(a == 0.0) { // not a true quadratic
  return -1 ;
} 

d = b*b - 4.0*a*c;
if(d < 0.0) { // No real roots 
  return -2;
}
if(d == 0) { // double root 
  roots->x1 = -b / (2.0*a);
  roots->x2 = roots->x1; 
  return 1;
}
// two roots 
sqrtd = sqrt(d);
roots->x1 = (-b + sqrtd)/(2.0*a);
roots->x2 = (-b - sqrtd)/(2.0*a);

return 2;
}

