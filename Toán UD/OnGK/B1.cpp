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
		printf("%d^%d * ",p[i],a[i]);
	}	
	printf("%d^%d",p[size-1],a[size-1]);
}

//3. Function to calculate sum of factors
int sumOfFactors(int n,int *p,int *a,int size)
{	int s = 1;
	for(int i = 0; i < size; i++){
		s*=(pow(p[i],a[i] + 1)-1)/(p[i] - 1);
	}
	return s;
}

int main()
{
	int size = 1000;
	int p[size], a[size],n;
	printf("Input number n = ");
	scanf("%d",&n);
	
	primeFactors(n,p,a,size);
	
	printf("\nSum of factors o(%d) = %d",n,sumOfFactors(n,p,a,size));
}
