#include<iostream>
#include <cmath>
using namespace std;



int nguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void TimSoNTTrongKhoang() {
	int d = 0;
	int sum = 0;
    int m, n;
    cout << "Nhap so dau, so cuoi: ";
    cin >> m >> n;
    cout << "\nCac so nguyen to tu " << m << " den " << n << " la: ";
    for (int i = m; i <= n; i++) {
        if (nguyenTo(i)) {
        	d++;
        	sum += i;
            cout << i << " ";
        }
    }
    cout << "\nSo luong cac so nguyen to la: " << d << "\n";
    cout << "\nTong cac so nguyen to la: " << sum;
}

int main() {
    TimSoNTTrongKhoang();
}
