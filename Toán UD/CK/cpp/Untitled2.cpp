#include <math.h>
#include <iostream>
#include <iomanip>
using namespace std;
double f(double x)
{
	double tmp1 = pow(log(2*pow(x, 2) + 1), 2) + 9*x;
double tmp2 = 3*exp(pow(x, 2)) - 5;
return tmp1 + tmp2;
}
double grad(double x)
{
	
double tmp1 = (18*pow(x, 2) + 8*x + 9)/(2*pow(x, 2) + 1);
double tmp2 = 6*x*exp(pow(x, 2));
return tmp1 + tmp2;
}
double GD_momentum(double x, double gamma, double alpha)
{
double deltax = 0;
double deltax_new = 0;
double x_new = 0;
int n_loop = 10000;
unsigned long count = 0;
for (int i = 0; i < n_loop; i++)
{
deltax_new = alpha * deltax - gamma * grad(x);
x_new = x + alpha * deltax_new - gamma * grad(x);
count++;
printf("loop %d: x = %f, f(x) = %1.5f \n", count, x, f(x));
if (fabs(x - x_new) < 0.00001)
{
break;
}
deltax = deltax_new;
x = x_new;
}
return f(x);
}
int main()
{
double x0 = -1.0;
double learning_rate = 0.001;
double momentum_coefficient = 0.5;
cout << "min(f(x)) = " << GD_momentum(x0, learning_rate, 
momentum_coefficient);
return 0;
}

