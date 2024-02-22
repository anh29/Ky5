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
  int soNguyenTo[100]; // M?ng luu tr? t?i da 100 s? nguyên t?
  int soLuongSoNT = 0;  // Bi?n d?m s? lu?ng s? nguyên t?

  int m=50, n=500;

  for (int i = m; i <= n; i++) {
    if (nguyenTo(i)) {
      soNguyenTo[soLuongSoNT++] = i;
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

