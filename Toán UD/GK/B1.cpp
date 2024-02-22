#include <bits/stdc++.h>
using namespace std;
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
bool prime(long long n){
    if (n==1) return false;
    for (int i=2; i*i<=n; i++)
    if (n%i==0) return false;
    return true;
}
int main(){
    long long n=2000,m,s=0;
    
    long long x=n-1;
    while (x>0 && !kt(x)) x--;

    long long y=n+1;
    while (!kt(y)) y++;
    
    cout<<"M = ";
    if (abs(x-n)<abs(y-n)) m=x; else m=y;
    cout<<m<<"\n";


    cout<<"Cac so nguyen to be hon M: ";
    for (int i=2; i<m; i++)
    if (prime(i)) {
        s+=i;
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<"Tong cac so nguyen to be hon M: "<<s;

}

