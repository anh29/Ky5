#include <bits/stdc++.h>
using namespace std;
double f(double x){
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
double gradient_descent(float x, float g, int n, float eps)
{
double x_new;
for (int i = 0; i < n; i++)
{
x_new = x - g * grad(x);
if (abs(grad(x)) < eps) 
{
break;
}
x = x_new;
}
return x_new;
}
int main()
{ 
double x = -1.0;
int n = 10000;
float g = 0.001;
float eps = 1e-5;
float x_min = gradient_descent(x, g, n, eps);
cout << "The minimum value of f(x) is: " << f(x_min) << " at x = " << x_min <<
endl;
}

