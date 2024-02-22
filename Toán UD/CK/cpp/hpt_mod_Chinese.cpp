#include <bits/stdc++.h>
#include<math.h>
#include<vector>
using namespace std;
#define max 100

int findMinX(int m[], int a[], int n)
{
    int x = 1; 
    while (true)
    {
        int j;
        for (j=0; j<n; j++ )
            if (x%m[j] != a[j])
               break;
        if (j == n)
            return x;
        x++;
    }
  
    return x;
}
void nhap(int a[], int m[],int n){
    for(int i = 0; i < n; i++){
        cout << "Nhap a[" << i << "]=" ; cin >> a[i];
        cout << "Nhap m[" << i << "]=" ; cin >> m[i];
    }
}
int main(){
    int a[max], m[max] ;//a mod m
    int n; int tich = 1;
    cout << "Nhap n = "; cin >> n;
    nhap(a, m, n);
    for(int i = 0; i < n; i++){
        cout <<endl<< a[i] <<" mod " << m[i];
        tich *= m[i];
    }
    cout << endl << "Ket qua: x = " << findMinX(m,a,n) << " (mod" << tich <<")";
}

