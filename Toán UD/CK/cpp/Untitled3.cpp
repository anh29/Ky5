#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int nguyenTo(int n) {
  if (n < 2) return 0;
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}

int main() {
  int m, n;
  cout << "Nhap so dau, so cuoi: ";
  cin >> m >> n;

  int soLuongSoNT = 0;
  for (int i = m; i <= n; i++) {
    if (nguyenTo(i)) soLuongSoNT++;
  }

  cout << "\nSo luong cac so nguyen to trong khoang " << m << " den " << n << " la: " << soLuongSoNT << endl;

  int soNguyenTo[soLuongSoNT]; // M?ng luu tr? các s? nguyên t?
  int i = 0;
  for (int j = m; j <= n; j++) {
    if (nguyenTo(j)) {
      soNguyenTo[i++] = j;
    }
  }

  int minDiff = INT_MAX;
  int soGanNhat = -1;
  for (int i = 0; i < soLuongSoNT; i++) {
    int diff = abs(soNguyenTo[i] - 300);
    if (diff < minDiff) {
      minDiff = diff;
      soGanNhat = soNguyenTo[i];
    }
  }

  cout << "\nSo nguyen to gan 300 nhat la: " << soGanNhat << endl;

  return 0;
}

