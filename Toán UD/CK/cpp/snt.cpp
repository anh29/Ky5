# include <stdio.h>
# include <math.h>
	
// 1. A function to find n = p1^a1.p2^a2...pk^ak
void primeFactors(int n,int *p,int *a,int &size){
	int b = n, j = 0, count = 0;
	while(n%2==0){
		count++;
		if(count == 1)	p[j] = 2;
		a[j] = count;
		n = n/2;
	}
		j++;
	for(int i = 3; i <= sqrt(n); i+=2){
		count = 0;
		while(n%i==0){
			count++;
			if(count == 1) 	p[j] = i;
			a[j] = count;
			n = n/i;
		}
		if(count != 0) j++;
	}
	
	if(n>2){
		p[j] = n;
		a[j] = 1;
	}
	else{
		j--;
	}
	size = j + 1;
	printf("%d = ",b);
	for(int i = 0; i < size - 1; i++){
		printf("%d^%d.",p[i],a[i]);
	}	
	printf("%d^%d",p[size-1],a[size-1]);
}

// 2. A function to print all prime factors of a given number n
int numberOfFactors(int *a,int size){
	int s = 1;
	for(int i = 0; i < size; i++)
	{
		s*= a[i] + 1;
	}
	return s;
}

//3. Function to calculate sum of factors
int sumOfFactors(int n,int *p,int *a,int size)
{	int s = 1;
	for(int i = 0; i < size; i++){
		s*=(pow(p[i],a[i] + 1)-1)/(p[i] - 1);
	}
	return s;
}

//5. Function to check perfect number
bool checkPerfectNumber(int n,int *p,int *a,int size){
	int s = sumOfFactors(n,p,a,size);
	if(n == s - n)
		return true;
	return false;
	}
	
//6. Function to find number of primes from 1 to n
float numberOfPrimes(int n){
	if(n <= 1) return 0;
	if(n==2) return 1;
	float num = n/log(n);
		return num;
	}
	
//7. Funtion to check n is prime or not
bool isPrime(int n){
	if(n < 2) return false;
	for(int i = 2; i <= sqrt(n); i++)
		if(n%i == 0) return false;
		return true;
}

//8.2 Function to find the nearest prime
long long findNearestPrime(long long n){
	if(isPrime(n)) return n;
	long long smaller = n - 1;
	long long larger = n + 1;
	while(true){
		if(isPrime(smaller))
			return smaller;
		if(isPrime(larger))
			return larger;
		smaller--;
		larger++;
		}
}

int main()
{
	int size = 1000;
	int p[size], a[size],n;
	printf("Input number n = ");
	scanf("%d",&n);
	
	printf("1:\n");
	primeFactors(n,p,a,size);
	
	printf("\n2:\n");
	printf("Number of factors t(%d) = %d",n,numberOfFactors(a,size));
	
	printf("\n3:\n");
	printf("Sum of factors o(%d) = %d",n,sumOfFactors(n,p,a,size));
	
	printf("\n4:\n");
	double t = pow(n,(numberOfFactors(a,size)/2));
	printf("Product of factors m(%d) = %f",n,t);
	
	printf("\n5:\n");
	if(checkPerfectNumber(n,p,a,size))
		printf("%d is a perfect number",n);
	else
		printf("%d is not a perfect number",n);
	printf("\n6:\n");
	printf("Number of primes from 1 to %d: %f",n,floor(numberOfPrimes(n)));
	
	printf("\n7:\n");
	if(isPrime(n))
	
		printf("%d is a prime",n);
	else
		printf("%d is not a prime",n);
		
	printf("\n8.2:\n");
	printf("The nearest prime with %d: %lld ",n,findNearestPrime(n));
	return 0;
}
