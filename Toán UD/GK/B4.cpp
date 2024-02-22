#include <bits/stdc++.h>
#include <iomanip>
#include "eigen/dense"
using Eigen::MatrixXd;
using namespace std;
using namespace Eigen;
void func_(){
	MatrixXd A(3,3),AT(3,3),S(3,3),temp1(3,1),V(3,3),VT(3,3),U(3,3);
	A(0,0)=9;   A(0,1)=11;   A(0,2)=15;
	A(1,0)=8;   A(1,1)=8;    A(1,2)=8;
	A(2,0)=15;  A(2,1)=11;   A(2,2)=9;
	
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) AT(i,j)=A(j,i);
	S=AT*A;
	
	SelfAdjointEigenSolver<MatrixXd> Matran(S);
	if (Matran.info() != Success) abort();	
	temp1=Matran.eigenvalues();
	temp1(0,0)=sqrt(temp1(0,0));
	temp1(1,0)=sqrt(temp1(1,0));
	temp1(2,0)=sqrt(temp1(2,0));
	MatrixXd X(3,3); for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) X(i,j)=0;
	X(0,0) = temp1(0,0);
	X(1,1) = temp1(1,0);
	X(2,2) = temp1(2,0);
}
int main()
{
	MatrixXd A(3,3),AT(3,3),S(3,3),temp1(3,1),V(3,3),VT(3,3),U(3,3);
	A(0,0)=9;   A(0,1)=11;   A(0,2)=15;
	A(1,0)=8;   A(1,1)=8;    A(1,2)=8;
	A(2,0)=15;  A(2,1)=11;   A(2,2)=9;
	
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) AT(i,j)=A(j,i);
	S=AT*A;
	
	SelfAdjointEigenSolver<MatrixXd> Matran(S);
	if (Matran.info() != Success) abort();	
	temp1=Matran.eigenvalues();
	temp1(0,0)=sqrt(temp1(0,0));
	temp1(1,0)=sqrt(temp1(1,0));
	temp1(2,0)=sqrt(temp1(2,0));
	MatrixXd X(3,3); for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) X(i,j)=0;
	X(0,0) = temp1(0,0);
	X(1,1) = temp1(1,0);
	X(2,2) = temp1(2,0);
	
	func_();
	
	
	V=Matran.eigenvectors();
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) VT(i,j)=V(j,i);
	
	for (int i=0; i<=2; i++) {
		MatrixXd temp2(3,1);
		MatrixXd temp3(3,1); 
		
		for (int j=0; j<=2; j++) temp3(j,0)=V(j,i);
		temp2=A*temp3;
		
		for (int j=0; j<=2; j++) 
		if (X(i,i)!=0) U(j,i) = temp2(j,0)*1.0/X(i,i); 
	}
	
	double temp[3][3];
	cout<<"Phan ra EigenDecomposition ma tran A = U * X * VT \n";
	cout<<"\nMa tran U\n";
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) temp[i][j]=U(i,j);
	for (int i=0; i<=2; i++) {
		for (int j=0; j<=2; j++) printf("%10.5f ",temp[i][j]); cout<<"\n";
	}
	
	cout<<"\nMa tran X\n";
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) temp[i][j]=X(i,j);
	for (int i=0; i<=2; i++) {
		for (int j=0; j<=2; j++) printf("%10.5f ",temp[i][j]); cout<<"\n";
	}
	
	cout<<"\nMa tran VT\n";
	for (int i=0; i<=2; i++) for (int j=0; j<=2; j++) temp[i][j]=VT(i,j);
	for (int i=0; i<=2; i++) {
		for (int j=0; j<=2; j++) printf("%10.5f ",temp[i][j]); cout<<"\n";
	}

