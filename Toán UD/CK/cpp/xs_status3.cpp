#include <bits/stdc++.h>
using namespace std;
void out(float P[][4])
{
for (int i=0;i<4;i++)
{
for (int j=0;j<4;j++)
{
cout << setprecision(4) << P[i][j] << "\t";
}
cout << endl;
}
}
void assign(float A[][4], float B[][4])
{
for (int i=0;i<4;i++)
{
for (int j=0;j<4;j++) B[i][j] = A[i][j];
}
}
void makeIdentity(float A[][4])
{
for (int i=0;i<4;i++)
{
A[i][i] = 1;
for (int j=0;j<4;j++) 
{
if (i!=j) A[i][j] = 0;
}
}
}
void multiply(float A[][4], float B[][4])
{
float C[4][4];
for (int i=0;i<4;i++)
{
for (int j=0;j<4;j++) 
{
C[i][j] = 0;
for (int k=0;k<4;k++) 
{
C[i][j] += A[i][k] * B[k][j];
}
}
}
assign(C,A);
}
void power(float A[][4], float B[][4], int n)
{ 
if (n==0) 
{
makeIdentity(B);
return;
}
if (n==1) 
{
assign(A,B);
return;
}
power(A,B,n/2);
multiply(B,B);
if (n%2!=0) multiply(B,A);
}
void result(float B[][4], string state[], string now)
{
float max = 0;
int row;
if (now == "1")
row = 0;
else if (now == "2")
row = 1;
else if (now == "3")
row = 2;
else if (now == "4")
row = 3;
{
cout << "Xac suat dat trang thai " + state[2] + " la: " << B[row][2] << endl;
}
}
int main()
{
float P[4][4] = {{0.4, 0.6, 0, 0}, {0.3, 0.2, 0.2, 0.3}, {0, 0.6, 0.4, 0}, {0, 
0.5, 0, 0.5}};
int n;
cout << "Nhap so giai doan: ";
cin >> n;
float B[4][4];
power(P,B,n);
string state[4] = {"1", "2", "3", "4"};
string now, after;
cout << "Trang thai hien tai: "; cin >> now;
result(B,state,now);
return 0;
}

