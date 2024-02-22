#include<iostream>
#include<math.h>
using namespace std;

bool ktra_matranvuong(int** a, int size, int b) {
	if (size != b) {
		return false;
	}
	for (int i = 0; i < size; i++) {
		if (a[i] == NULL) {
			return false;
		}
	}
	return true;
}

bool ktr_matrandxung(int** a, int size, int b) {
	if (ktra_matranvuong(a, size, b)) {
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				if (a[i][j] != a[j][i]) {
					return false;
				}
			}
		}
		return true;
	}
}

int determinant(int** matrix, int n) {
	// Tru?ng h?p co b?n: ma tr?n 1x1
	if (n == 1) {
		return matrix[0][0];
	}

	int det = 0; // Bi?n luu gi� tr? d?nh th?c

	// T?o ma tr?n con
	int** submatrix = new int* [n - 1];
	for (int i = 0; i < n - 1; i++) {
		submatrix[i] = new int[n - 1];
	}

	// T�nh d?nh th?c b?ng c�ch l?y c�c ph?n t? h�ng d?u ti�n nh�n v?i d?nh th?c c?a ma tr?n con
	for (int k = 0; k < n; k++) {
		int subi = 0; // Ch? s? h�ng c?a ma tr?n con

		// T?o ma tr?n con b?ng c�ch lo?i b? h�ng d?u ti�n v� c?t k
		for (int i = 1; i < n; i++) {
			int subj = 0; // Ch? s? c?t c?a ma tr?n con

			for (int j = 0; j < n; j++) {
				if (j == k) {
					continue;
				}
				submatrix[subi][subj] = matrix[i][j];
				subj++;
			}
			subi++;
		}

		// �?nh th?c c?a ma tr?n con du?c t�nh d? quy
		int subdet = determinant(submatrix, n - 1);

		// �?nh th?c c?a ma tr?n g?c du?c t�nh b?ng c�ch l?y t?ng c�c ph?n t? h�ng d?u ti�n nh�n v?i d?nh th?c c?a ma tr?n con
		if (k % 2 == 0) {
			det += matrix[0][k] * subdet;
		}
		else {
			det -= matrix[0][k] * subdet;
		}
	}

	return det;
}

int** TaoMang(int size) {
	int** L = new int* [size];
	for (int i = 0; i < size; i++) {
		L[i] = new int[size];
		for (int j = 0; j < size; j++) {
			L[i][j] = 0;
		}
	}
	return L;
}

void cholesky(int** a, int size, int cot) {
	if (ktra_matranvuong(a, size, cot) && ktr_matrandxung(a, size, cot) && determinant(a, size) > 0) {
		int** L = TaoMang(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= i; j++) {
				int sum = 0;
				if (i == j) {
					for (int k = 0; k < j; k++) {
						sum += pow(L[j][k], 2);
					}
					L[j][j] = sqrt(a[j][j] - sum);
				}
				else if (i > j) {
					for (int k = 0; k < j; k++) {
						sum += (L[i][k] * L[j][k]);
					}
					L[i][j] = (a[i][j] - sum) / L[j][j];
				}
			}
		}
		cout << "------------Cholesky A = LLt-----------------" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < cot; j++) {
				cout << L[i][j] << " ";
			}

			cout << "\t\t";
			for (int j = 0; j < cot; j++) {
				cout << L[j][i] << " ";
			}
			cout << endl;
		}
	}
}

void cholesky_decomposition2(int** a, int size, int cot) {
	if (ktra_matranvuong(a, size, cot) && ktr_matrandxung(a, size, cot) && determinant(a, size) > 0) {
		int** L = TaoMang(size);
		int** D = TaoMang(size);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j <= i; j++) {
				int sum = 0;
				for (int k = 0; k < j; k++) {
					sum += L[i][k] * D[k][k] * L[j][k];
				}
				if (i == j) {
					D[i][i] = a[i][i] - sum;
					L[j][j] = 1;
				}
				else {
					L[i][j] = (a[i][j] - sum) / D[j][j];
				}
			}
		}
		cout << "-----------------------------" << endl;
		cout << "Cholesky decomposition variant" << endl;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < cot; j++) {
				cout << L[i][j] << " ";
			}

			cout << "\t\t";
			for (int j = 0; j < cot; j++) {
				cout << D[i][j] << " ";
			}
			cout << "\t\t";
			for (int j = 0; j < cot; j++) {
				cout << L[j][i] << " ";
			}
			cout << endl;
		}
	}
}

int main() {
	int size, cot;
	do
	{
		cout << "Nhap so dong ma tran: ";
		cin >> size;
		cout << "\nNhap so cot: ";
		cin >> cot;
	} while (size <= 0 || cot <= 0);
	int** a = new int* [size];
	for (int i = 0; i < size; i++)
	{
		a[i] = new int[cot];
	}
	cout << "Nhap gia tri cho cac phan tu trong mang:\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < cot; j++) {
			cout << "Nhap gia tri cho phan tu [" << i << "][" << j << "]: ";
			cin >> a[i][j];
		}
	}
	cout << "Mang vua nhap:\n";
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < cot; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cholesky(a, size, cot);
	cholesky_decomposition2(a, size, cot);
	delete[] a;

	return 0;
}
