#include<iostream>
#include <cmath>
using namespace std;
void phantichsnt(int n) {
    int dem;
    for (int i = 2; i <= n; i++) {
        dem = 0;
        while (n % i == 0) {
            ++dem;
            n /= i;
        }
        if (dem) {
            cout << i;
            if (dem > 1) cout << "^" << dem;
            if (n > i) {
                cout << " * ";
            }
        }
    }
}
int Dem_UocSo(int N)
{
    int dem = 0;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
            dem++;
    }

    return dem;
}
void TongUocSo(int n) {
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            dem += i;
    }
    cout << dem;
}
void TichUocSo(int n) {
    int dem = 1;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            dem *= i;
    }
    cout << dem;
}
bool check(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i;
    }
    if (sum == n) return true;
    return false;
}
long long MatDoSoNgto(long long n) {
    long long result = n / log(n);
    return round(result);
}
int nguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void TimSoNTTrongKhoang() {
    int m, n;
    cin >> m >> n;
    cout << "\nCac so nguyen to tu " << m << " den " << n << " la: ";
    for (int i = m; i <= n; i++) {
        if (nguyenTo(i)) {
            cout << i << " ";
        }
    }
   
}
int timsogannhat(int n) {
    int nearestPrime = 0;
    int distance = INT_MAX;

    // Tìm số nguyên tố gần nhất với số n
    for (int i = 2; i <= n; i++) {
        if (nguyenTo(i)) {
            int currDistance = abs(n - i);
            if (currDistance < distance) {
                nearestPrime = i;
                distance = currDistance;
            }
        }
    }

    return nearestPrime;
}
int main() {
    int n,m;
    cout << "\nNhap n = ";
    cin >> n;
    cout << "Phan tich so nguyen to cua " << n << " la: "; phantichsnt(n);
    cout << "\nDem uoc = " << Dem_UocSo(n) << endl;
    cout << "Tong uoc so cua " << n << " la: "; TongUocSo(n);
    cout << "\nTich uoc so cua " << n << " la: "; TichUocSo(n);
    if (check(n)) {
        cout << "\nSo " << n << " la so hoan hao";
    }
    else cout << "\nSo " << n << " khong phai so hoan hao";

    cout << "\nMat do so nguyen to " << MatDoSoNgto(n)<<endl;
    TimSoNTTrongKhoang();
    cout << "\nSo nguyen to gan nhat "<< timsogannhat(n);
    
}
