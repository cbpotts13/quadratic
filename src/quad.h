


// coefs for ax^2 + bx + c = 0
typedef struct {
  double	a;
  double	b;
  double	c;
} Values;

// Real roots for ax^2 + bx + c = 0
typedef struct {
  double	x1;
  double	x2;
} Roots;

// quadratic eqaution solver
int solve_quad(Values *coef, Roots *root);
