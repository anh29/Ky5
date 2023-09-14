#include <iostream>
#include <cmath>
using namespace std;
#define MAX 50

void inputMatrix(int matrix[][MAX], int n) {
    printf("Enter elements for matrix: \n");

    for (int i = 1; i <= n; i++) {
        printf("Input row [%d] of matrix: ", i);
        for (int j = 1; j <= n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

float* solve(float a, float b, float c, float d) 
{
	float result[3] = {0};
	const double PI = 4.0 * atan( 1.0 );
   	cout << "Solve " << a << "x^3 + " << b << "x^2 + " << c << "x + " << d << " = 0\n";
   
   // Reduced equation: X^3 - 3pX - 2q = 0, where X = x-b/(3a)
   double p = ( b * b - 3.0 * a * c ) / ( 9.0 * a * a );
   double q = ( 9.0 * a * b * c - 27.0 * a * a * d - 2.0 * b * b * b ) / ( 54.0 * a * a * a );
   double offset = b / ( 3.0 * a );

   // Discriminant
   double discriminant = p * p * p - q * q;

   cout << "\nRoots:\n";
   if ( discriminant > 0 )           // set X = 2 sqrt(p) cos(theta) and compare 4 cos^3(theta)-3 cos(theta) = cos(3 theta)
   {
      double theta = acos( q / ( p * sqrt( p ) ) );
      double r = 2.0 * sqrt( p );
      for ( int n = 0; n < 3; n++ ) 
	  {
	  	result[n] = r * cos( ( theta + 2.0 * n * PI ) / 3.0 ) - offset;
	  }
   }
   else 
   {
      double gamma1 = cbrt( q + sqrt( -discriminant ) );
      double gamma2 = cbrt( q - sqrt( -discriminant ) );

		result[0] = gamma1 + gamma2 - offset;

      double re = -0.5 * ( gamma1 + gamma2 ) - offset;
      double im = ( gamma1 - gamma2 ) * sqrt( 3.0 ) / 2.0;
      if ( discriminant == 0.0 )                // Equal roots (hmmm, floating point ...)
      {
		result[1] = re;
		result[2] = re;
      }
   }
   return result;
}

float* gtR (int matrix[][MAX], int n)
{
	int m = n;
	float a = -1;
	float b = matrix[1][1] + matrix[2][2] + matrix[3][3];
	float c = matrix[1][3]*matrix[3][1] + matrix[2][3]*matrix[3][2] + matrix[1][2]*matrix[2][1] 
		- matrix[1][1]*matrix[3][3] - matrix[2][2]*matrix[3][3] - matrix[1][1]*matrix[2][2];
	float d = matrix[1][3]*matrix[3][2]*matrix[2][1] + matrix[1][2]*matrix[2][3]*matrix[3][1] + matrix[1][1]*matrix[2][2]*matrix[3][3] 
		- matrix[1][3]*matrix[3][1]*matrix[2][2] - matrix[2][3]*matrix[3][2]*matrix[1][1] - matrix[1][2]*matrix[2][1]*matrix[3][3];

	float *gt = solve(a, b, c, d);
	
	return gt;
}

int main()
{
    int n = 3;
	
	int matrix[n][MAX];
	inputMatrix(matrix, n);
	float *gt = gtR(matrix, n);
	for (int i=0; i<n;i++)
	{
		cout <<gt[i] << "  ";
	}
}
