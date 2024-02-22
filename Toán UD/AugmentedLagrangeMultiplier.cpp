#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define eps 1e-3
double g(double x1, double x2)
{
    return x1 + x2 - 5.0;
}

void AugmentedLagrangeMultiplier(double r,double lamda){
	double x1 = (10 *r* r + 60*r -6*lamda -r*lamda) / ((14 + 5 * r) * (12 + 2 * r));
    double x2 = (20*r-2*lamda)/(14+5*r);
    cout << setw(15) << "lamda" << setw(15) << "r" << setw(15) << "x1" << setw(15) << "x2" << setw(15) << "h" << endl;
    cout << setw(15) << lamda << setw(15) << r << setw(15) << x1 << setw(15) << x2 << setw(15) << g(x1, x2) << endl;
    while (abs(g(x1, x2)) >= eps)
    {
        lamda = lamda + 2 * r * g(x1, x2);
        x1 = (10 * r * r + 60*r -6*lamda -r*lamda) / ((14 + 5 * r) * (12 + 2 * r));
        x2 = (20*r-2*lamda)/(14+5*r);
        cout << setw(15) << lamda << setw(15) << r << setw(15) << x1 << setw(15) << x2 << setw(15) << g(x1, x2);
        cout << endl;
    }
}
int main()
{
	double r=1,lamda=0.0;
	cout << "Minimize f(X)=6*x1^2 + 4*x1*x2 + 3*x2^2"<<endl;
	cout << "Augmented Lagrange Multiplier Method:" << endl;
    AugmentedLagrangeMultiplier(r,lamda);
}
