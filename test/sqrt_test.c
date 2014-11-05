#include <stdlib.h>
#include "cunit.h"
#include "qsolve_roots.h"


int main() {
Coef	coefs;   // a, b and c for the quadratic eqaution
Root	roots;   // Root struct with x1 and x1
int	ret;     // return value from qsolve_roots
// double  a, b, c; // scratch variables
double  x1, x2;  // scratch variables


// initialize the unit testing framework
cunit_init();

//  A bad unit tet
coefs.a = 1.0;
coefs.b = 2.0;
coefs.c = 1.0;
ret = qsolve_roots(&coefs, &roots);
assert_eq("ret",ret,2);
assert_feq("x1",roots.x1,-2.0);
assert_feq("x2",roots.x2,-2.0);

// A bad unit test, wrong order
// (x - x1)*(x - x2) = 0
x1 = 3.1;
x2 = 3.3;
coefs.a = 1.0;
coefs.b = -x1 + -x2;
coefs.c = x1*x2;
ret = qsolve_roots(&coefs, &roots);
assert_eq("ret",ret,2);
assert_feq("x1",roots.x1, x1);
assert_feq("x2",roots.x2, x2);

// A bad unit test, need to allow for round off!
// (x - x1)*(x - x2) = 0
x1 = 3.1;
x2 = 3.3;
coefs.a = 1.0;
coefs.b = -x1 + -x2;
coefs.c = x1*x2;
ret = qsolve_roots(&coefs, &roots);
assert_eq("ret",ret,2);
assert_feq("x1",roots.x1, x2);
assert_feq("x2",roots.x2, x1);

// A "good" unit test, need to allow for round off!
// qsolve_roots() passes this one. ;-)
// This allows about one base 10 least significant digit of error
// (x - x1)*(x - x2) = 0
x1 = 3.1;
x2 = 3.3;
coefs.a = 1.0;
coefs.b = -x1 + -x2;
coefs.c = x1*x2;
ret = qsolve_roots(&coefs, &roots);
assert_eq("ret",ret,2);
assert_feqrerr("x1",roots.x1, x2, 10.0*cunit_dmacheps );
assert_feqrerr("x2",roots.x2, x1, 10.0*cunit_dmacheps );
exit(0);
}
