#include <iostream>
#include <math.h>

#define ESP 0.000000018
#define ldouble long double

ldouble Func1(ldouble x)
{
	double a = pow(exp(2 * x) + x - 10, 2);
	double b = pow(x + 1, 2);
	return a + 2 * b;
}

ldouble Derivative1Func1(ldouble x)
{
	return 4 * exp(4 * x) + (4 * x - 38) * exp(2 * x) + 6 * x - 16;
}

ldouble Derivative2Func1(ldouble x)
{
	return 16 * exp(4 * x) + (8 * x - 72) * exp(2 * x) + 6;
}

ldouble Func2(ldouble x)
{
	ldouble a = pow(exp(2 * pow(x, 2) + 1) - 2 * x + 1, 2);
	ldouble b = pow(x + 1, 3);
	return a - 5 * b;
}

ldouble Derivative1Func2(ldouble x)
{
	return 2 * (exp(2 * pow(x, 2) + 1) - 2 * x + 1) * (4 * x * exp(2 * pow(x, 2) + 1) - 2) - 15 * pow(x + 1, 2);
}

ldouble Derivative2Func2(ldouble x)
{
	return 8 * exp(2 * pow(x, 2) + 1) * ((8 * pow(x, 2) + 1) * exp(2 * pow(x, 2) + 1) - 8 * pow(x, 3) + 4 * pow(x, 2) - 6 * x + 1) - 30 * x - 22;
}

ldouble GradientDescent(ldouble initialX, ldouble learningRate, int iterations, ldouble(*func1)(ldouble))
{
	double x = initialX;
	double velocity = 0;

	for (int i = 0; i < iterations; i++)
	{
		double grad = func1(x);
		velocity = -learningRate * grad;
		x += velocity;
	}
	
	return x;
}

ldouble GradientDescentMomentum(ldouble initialX, double learningRate, double momentum, int iterations,
	ldouble(*func1)(ldouble))
{
	double x = initialX;
	double velocity = 0;

	for (int i = 0; i < iterations; i++)
	{
		double grad = func1(x);
		velocity = -learningRate * grad + velocity * momentum;
		x += velocity;
	}

	return x;
}

ldouble Newton(ldouble initialX, int iterations, ldouble(*func1)(ldouble), ldouble(*func2)(ldouble))
{
	double x = initialX;
	double velocity = 0;

	for (int i = 0; i < iterations; i++)
	{
		velocity = -func1(x) / func2(x);
		x += velocity;
	}

	return x;
}

int main()
{
	std::cout << "Function 1:\n";
	std::cout << "Gradient Descent:\n";
	std::cout << GradientDescent(6, 0.001, 10000, Derivative1Func1) << "\n\n";

	std::cout << "Gradient Descent Momentum:\n";
	std::cout << GradientDescentMomentum(6, 0.001, 0.002, 10000, Derivative1Func1) << "\n\n";

	std::cout << "Newton:\n";
	std::cout << Newton(6, 10000, Derivative1Func1, Derivative2Func1) << "\n\n";


	std::cout << "Function 2:\n";
	std::cout << "Gradient Descent:\n";
	std::cout << GradientDescent(-0.5, 0.0001, 10000, Derivative1Func2) << "\n\n";

	std::cout << "Gradient Descent Momentum:\n";
	std::cout << GradientDescentMomentum(-0.5, 0.0001, 0.0002, 10000, Derivative1Func2) << "\n\n";

	std::cout << "Newton:\n";
	std::cout << Newton(6, 10000, Derivative1Func2, Derivative2Func2) << "\n\n";
}
