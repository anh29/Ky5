#include <stdio.h>

// Ham tim uoc so chung lon nhat mo rong va luu gia tri x, y sao cho ax + by = gcd(a, b)
int extended_gcd(int a, int b, int *x, int *y) {
  if (a == 0) {
    *x = 0; // Gan gia tri x bang 0
    *y = 1; // Gan gia tri y bang 1
    return b;
  }

  int g = extended_gcd(b % a, a, x, y); // Goi de quy de tim uoc so chung lon nhat
  int temp = *x;
  *x = *y - (b / a) * temp; // Cap nhat gia tri x
  *y = temp; // Cap nhat gia tri y
  return g; // Tra ve gia tri gcd(a, b)
}

// Ham tim nghiem cua phuong trinh diophantine ax + by = c, luu gia tri x, y vao bien truyen vao
int diophantine_solution(int a, int b, int c, int *x, int *y) {
  int g = extended_gcd(a, b, x, y); // Goi ham extended_gcd de tim uoc so chung lon nhat va gia tri x, y
  
  // Kiem tra neu c khong chia het cho uoc so chung lon nhat, khong co nghiem nguyen
  if (c % g != 0) {
    return 0;
  }

  // Luu nghiem cua phuong trinh diophantine vao x, y
  *x *= c / g;
  *y *= c / g;
  return 1;
}

int main() {
  int a, b, c;
  printf("Nhap a: ");
  scanf("%d", &a);
  printf("Nhap b: ");
  scanf("%d", &b);
  printf("Nhap c: ");
  scanf("%d", &c);

  int x, y;
  int has_solution = diophantine_solution(a, b, c, &x, &y);

  // In ket qua ra man hinh
  if (has_solution) {
    printf("Nghiem cua phuong trinh %dx + %dy = %d la (x, y) = (%d, %d)\n", a, b, c, x, y);
  } else {
    printf("Phuong trinh %dx + %dy = %d khong co nghiem nguyen.\n", a, b, c);
  }

  return 0;
}

