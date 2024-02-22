#include <bits/stdc++.h>
#include <vector>
#include<math.h>
using namespace std;
#define max 100001
int spf[max];
 
// ---------
// Time Complexity : O(nloglogn)
// -----------
void sieve(){ 
    spf[1] = 1;
    for (int i=2; i<max; i++)
        spf[i] = i;
    for (int i=4; i<max; i+=2)
        spf[i] = 2;
 
    for (int i=3; i<sqrt(max); i++){
        if (spf[i] == i){
            for (int j=i*i; j<max; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
//---------
// Time Complexity : O(log n)
// -----------
vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1){
        ret.push_back(spf[x]); 
        x = x / spf[x];
    }
    return ret;
}
vector<int> getDistinctPrimes(int x, vector<int> listP){
    vector<int> p;
    p.push_back(listP[0]);
    for(int i = 1; i < listP.size(); i++ )
        if(listP[i-1] != listP[i]) p.push_back(listP[i]);
    return p; 
}
vector<int> num_prime(int x, vector<int> listP){  //mang a
    int y,d = 1;
    vector<int> count;
    for(int i = 1; i < listP.size(); i++ ){
        if(listP[i-1] == listP[i]) d+=1;
        else {
            count.push_back(d);
            d = 1;
        }
        // count.push_back(d);
    }
    count.push_back(d);
    return count;
}
// hàm tính s? s? nguyên t? cùng nhau v?i n:
int num_coprime(vector<int> p, vector<int> a, int n){
    int t = 1;
    for(int i = 0; i<p.size(); i++){
        t *= pow(p[i], a[i] - 1) * (p[i]-1);
    }
    return t;
}
// tìm u?c chung l?n nh?t:
int gcd(int a, int b){
    if(a == 0 || b == 0) return a+b;
    while(a != b){
        if(a > b) a -= b;
        else b -=a;
    }
    return a;
}
// Liet ke cac so dong nguyen to 1-> n
vector<int> listCoprime(int n){
    vector<int> list;
    for(int i = 1; i <n; i++){
        if(gcd(i, n) == 1) list.push_back(i);
    }
    return list;
}
 int ktSNT(int a){
     // int i=0;
     int i;
     if(a < 2) return 0;
     for(i=2; i<= (int) sqrt(a); i++)
         if(a % i == 0) return 0;
     return 1;
 }
int main(){
    //Bài 1: Liet ke cac so dong nguyen to 1-> n
    sieve();
    int n;
    cout << "Nhhap vao so nguyen n = ";
    cin >> n;
    vector <int> listP = getFactorization(n);
    vector <int> p = getDistinctPrimes(n, listP);
    vector <int> a = num_prime(n, listP);
    vector <int> l = listCoprime(n);

    cout << "So cac so nguyen cung nhau voi " << n << " : " << num_coprime(p,a,n) << endl;
    cout << "Liet ke cac so nguyen cung nhau voi " << n << " : " ; 

    // n co phai so nguyen to ko
    for(int i=0; i<l.size(); i++) cout << l[i] <<", ";
    //
    if((n-1) == num_coprime(p,a,n)) cout << endl << n << " là so nguyen to." << endl;
    else cout << endl << n << " khong phai so nguyen to." << endl;
    //
    if(ktSNT(n)) cout << endl << n << " là so nguyen to." << endl;
    else cout << endl << n << " khong phai so nguyen to." << endl;
}
