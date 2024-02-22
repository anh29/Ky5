#include <bits/stdc++.h>
#include <iomanip>
#include "eigen/dense"
using Eigen::MatrixXd;
using namespace std;
using namespace Eigen;
void inverse_(){
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
		
}
int main()
{
	MatrixXd A(3,3),P(3,3),P1(3,3),D(3,3);
	A(0,0)=13; A(0,1)=-3;  A(0,2)=4;
	A(1,0)=-3; A(1,1)=20;  A(1,2)=11;
	A(2,0)=4;  A(2,1)=11;   A(2,2)=13;
	
	P1(0,0)=-0.432; P1(0,1)=-0.533; P1(0,2)=0.727;
	P1(1,0)=-0.902; P1(1,1)=0.251;  P1(1,2)=-0.351;
	P1(2,0)=-0.004; P1(2,1)=0.808;  P1(2,2)=0.589;
	
	
	SelfAdjointEigenSolver<MatrixXd> Matran(A);
	if (Matran.info() != Success) abort();	
	
	P=Matran.eigenvectors();
	inverse_();
	D=P1*A*P;
	cout<<"Phan ra eigendecomposition ma tran A = P * D * P^-1\n";
	
	cout<<"\nMa tran P\n";
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++) printf("%10.5f ",P(i,j)); cout<<"\n";
	}
	
	cout<<"\nMa tran D\n";
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++) printf("%10.5f ",D(i,j)); cout<<"\n";
	}
	
	
	cout<<"\nMa tran P^-1\n";
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++) printf("%10.5f ",P1(i,j)); cout<<"\n";
	}
	
	
}

