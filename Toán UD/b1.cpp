#include <bits/stdc++.h>
using namespace std;

long long snt(int n) {
    long long max=1;
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            max = i;
        }
    }
    cout << "M = " << max << "\n";
    return max;
}
bool prime(long long n){
    if (n==1) return false;
    for (int i=2; i*i<=n; i++)
    if (n%i==0) return false;
    return true;
}
long long sum(long long n){
    if (n==1) return 0;
    long long res=0;
    for (int i=1; i<n; i++)
    if (n%i==0)  {
       res+=i;
    }
    return res;
}
bool kt(long long n){
    return n==sum(n);
}

void shh(long long n) {
	long long d=0, t=0;
	cout << "So hoan hao (giua 1 va M)";
	for (int i=1; i<n; i++) {
		if (kt(i)) {
			cout << i << "\t";
			t += i;
			d++;
		}
	}
	cout << "\nSo luong cac so hoan hao: " << d << "\n";
	cout << "Tong cac so hoan hao: "<< t <<"\n";
}

void sntbe(long long m) {
	long long s=0;
	cout<<"Cac so nguyen to be hon M: \n";
    for (int i=2; i<m; i++)
    if (prime(i)) {
        s+=i;
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Tong cac so nguyen to be hon M: "<<s;
}
int main(){
    long long n=97700,m,s=0;
    
    m = snt(n);

	shh(m);
	
	sntbe(m);
	
	return 0;
}

