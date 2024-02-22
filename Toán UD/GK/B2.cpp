#include <bits/stdc++.h>
using namespace std;
long long power1(long long x,long long n){
    long long res=1;
    do {
        if (n%2==1) res=res*x;
        x=x*x;
        n/=2;
    } while (n);
    return res;
}
long long power2(long long x,long long n,long long mod){
    long long res=1;
    do {
        if (n%2==1) res=(res*x)%mod;
        x=(x*x)%mod;
        n/=2;
    } while (n);
    return res%mod;
}
long long gcd(long long a,long long b){
    if (b==0) return a;
    return gcd(b,a%b);
}
long long Euler(long long n){
    long long res=1;
    int i=2; 
    do {
        while (n%i!=0) i++;
        int d=0;
        while (n%i==0) {
            d++;
            n/=i;
        }
        res=res * power1(i,d-1) * (i-1);
    } while (n!=1);
    return res;
}
long long Modulo_Inverse(long long a,long long m){
    return power2(a,Euler(m)-1,m);
}
int main(){
    long long n=4;
    long long a[]={0,2,4,6,8};
    long long m[]={0,7,9,11,13};
    long long temp=m[1],M=m[1];
    for (int i=2; i<=n; i++) {
        temp=gcd(temp,m[i]);
        M=M*m[i];
        if (temp!=1) {
            cout<<"Vo nghiem";
            break;
        }
    }
    long long res=0;
    for (int i=1; i<=n; i++) res = res + a[i] * (M/m[i]) * Modulo_Inverse(M/m[i],m[i]);
    cout<<"X = "<<res%M;
    cout<<" * k ( Voi k>0) ";
}

