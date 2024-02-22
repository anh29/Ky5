#include <stdio.h>
#include <math.h>
int modInverse (int x, int m)
{
	int i;
	for (i=0; ; i++)
	{
		if ((1+i*m) % x == 0)
		{
			return (1 + i*m) / x;
		}
	}
}

int ChineseRemainderTheorem (int *a, int *m, int n)
{
	int X[n], mod_in[n];
	int t = 1, x = 0, x_min;
	for (int i = 0; i<n; i++)
	{
		t *= m[i];
	}
	
	for (int i = 0; i<n; i++)
	{
		X[i] = t/m[i];
		mod_in[i] = modInverse(X[i], m[i]);
	}
	
	for (int i = 0; i<n; i++)
	{
		x += a[i]*X[i]*mod_in[i];
	} 
	
	x_min = x%t; 
	return x_min;
}

int main()
{
	int q;
	printf("\nInput number of equations (n): "); scanf("%d", &q);
	int x[q], y[q];
	for (int i=0 ; i<q ; i++)
	{
		printf("\nInput a_n, m_n: ");
		scanf("%d %d", &x[i], &y[i]);
	}
	
	int x_C = ChineseRemainderTheorem(x, y, q);
	
	printf("Chinese remainder theorem: x = %d\n", x_C);

}
