#include <stdio.h>
#include <math.h>

int gcd_1 (int a, int b)
{
	if (a == 0 || b == 0){
        return a + b;
    }
    
    while (a != b){
        if (a > b){
            a -= b;
        }else{
            b -= a;
        }
    }
    
    return a;
}

int lcm_1 (int a, int b)
{
	int step;
	 
	if(a>b)
    {
        step = a;
    } else
    {
        step = b;
    }
    
    for(int i = step; i <= a*b; i+= step){
        if(i % a == 0 && i % b == 0)
        {
            return i; 
        }
    }
} 

int gcd (int a, int b) 
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int lcm (int a, int b)
{
	return (a*b)/gcd(a,b);
}

int phi (int n)
{
	int d = 0;
	printf("\nCoprime to %d : ", n);
	
	for (int i = 1; i<n; i++)
	{
		if (gcd(i,n) == 1)
		{
			printf("%d ", i);
			d++;
		}
	}
	return d;
}

bool checkPrime (int n)
{
	if (phi(n) == n-1)
	{
		return true;
	}
	return false;
}

bool checkModularAdd (int x, int y, int m)
{
	int a = (x+y) % m;
	int b = (x%m + y%m) % m;
	if (a == b)
	{
		return true;
	}
	return false;
}

bool checkModularSub (int x, int y, int m)
{
	int a = (x-y) % m;
	int b = (x%m - y%m) % m;
	if (a == b)
	{
		return true;
	}
	return false;
}

bool checkModularMult (int x, int y, int m)
{
	int a = (x*y) % m;
	int b = (x%m * y%m) % m;
	if (a == b)
	{
		return true;
	}
	return false;
}

int modPow (int x, int n, int m)
{
	if (n == 0) return 1%m;
	long long u = modPow(x, n/2, m);
	u = (u*u)%m;
	if (n%2 == 1) u = (u*x)%m;
	return u; 
}

bool checkModularPow (int x, int n, int m)
{
	int a = modPow(x, n, m);
	int b = modPow(x%m, n, m);
	if (a == b)
	{
		return true;
	}
	return false;
}

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
	int a, b;
	int n;
	int m;
	int q;
	
	printf("Input a, b: "); scanf("%d %d", &a, &b);
	printf("\nUCLN(%d,%d) la: %d\n", a, b, gcd(a, b));
	printf("\nBCNN(%d,%d) la: %d\n", a, b, lcm(a, b));
 
	printf("\nInput number: ");
	scanf("%d", &n);
	
	if(checkPrime(n))
	{
		printf("\n%d is prime.\n", n);
	} 
	else
	{
		printf("\n%d is not prime.\n", n);
	}
	
	if(checkModularAdd(a, b, n))
	{
		printf("\n%d and %d are congruent (mod %d)\n", a, b, n);
	}
	else
	{
		printf("\n%d and %d are not congruent (mod %d)\n", a, b, n);
	}

	m = modInverse(a,n);
	printf("\nThe inverse of %d mod %d: %d\n", a, n, m);

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
