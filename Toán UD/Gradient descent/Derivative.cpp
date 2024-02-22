#include <iostream>
#include <cmath>
using namespace std;

double f1(double x)
{
	return pow(exp(2*x) + x - 10, 2) + 2 * pow(x + 1, 2);
}

double f2(double x)
{
	return pow(exp(2*x+1) - 2*x +1 ,2) - 5*pow(x+1, 3);
}

double firstDerivative (double x, double h = 1e-5) 
{
//	return (f1(x+h)-f1(x))/h;
	return (f2(x+h)-f2(x))/h;
}

double secondDerivative (double x, double h = 1e-5)
{
	return (firstDerivative(x+h) - firstDerivative(x)) / h;
}

int main() 
{
	cout << firstDerivative(0.5) << endl;
	cout << secondDerivative(0.5);	
}
