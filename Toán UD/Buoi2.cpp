#include <iostream>

using namespace std;

// Hàm tính GCD (ước chung lớn nhất) của hai số nguyên và tính đồng thời x và y theo thuật toán Euclid mở rộng
int gcdExtended(int a, int b, int& x, int& y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);

    x = y1 - (b / a) * x1;
    y = x1;

    return gcd;
}

// Hàm tính modular inverse của a theo modulo m
int modularInverse(int a, int m) {
    int x, y;
    int gcd = gcdExtended(a, m, x, y);

    if (gcd != 1) {
        // Modular inverse không tồn tại nếu gcd(a, m) != 1
        return -1;
    } else {
        // Đảm bảo kết quả nằm trong khoảng [0, m-1]
        return (x % m + m) % m;
    }
}

int main() {
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    int gcd = gcdExtended(a, b, x, y);
    int inverse = modularInverse(a, b);

    cout << "Uoc chung lon nhat cua " << a << " va " << b << " la " << gcd << endl;

    if (inverse != -1) {
        cout << "Modular inverse cua " << a << " modulo " << b << " la: " << inverse << endl;
    } else {
        cout << "Modular inverse khong ton tai." << endl;
    }

    return 0;
}
