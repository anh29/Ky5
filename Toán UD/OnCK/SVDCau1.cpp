#include<iostream>
#include<iomanip>
#include<Eigen/Dense>
#include<Eigen/EigenValues>

using namespace std;
using namespace Eigen;
float data[1000];
int rows,cols;

struct matran{
	int sd,sc;
	float coef[100][100];
};

struct matran createMatrix(int m,int n)
{
	struct matran A;
	A.sd=m;
	A.sc=n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		A.coef[i][j]=0;
	}
	return A;
}

int input()
{
	cout << "Matrix A:"<<endl;
    for(int i=0;i<rows*cols;i++){
    	cin>>data[i];
	}
}

int outputMatrix()
{
	cout << "Matrix A:"<<endl;
    for(int i=0;i<rows*cols;i++){
    	if (i % cols == 0)
    		cout << "\n";
    	cout << data[i] << setw(5);
	}
}

void SVD()
{
	MatrixXf matrix(rows,cols);
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			matrix(i,j)= data[i*cols+j];
		}
	}
	
	struct matran sig= createMatrix(rows,cols);
	MatrixXf sigma(rows,cols);
	MatrixXf matrixA= matrix.transpose()*matrix;
	
	SelfAdjointEigenSolver<MatrixXf> esA(matrixA);
	int k=0;
	VectorXf temp = esA.eigenvalues();
	
	for(int i=0;i<temp.size();i++)
	{
		if(fabs(temp[i]<10e-4)) temp[i]=0;
		temp[i]=sqrt(temp[i]);
		sig.coef[temp.size()-i-1][temp.size()-i-1]=temp[i];
	}
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			sigma(i,j)=sig.coef[i][j];
			if(fabs(sigma(i,j))<10e-4)
			sigma(i,j)=0;
		}
	}


	MatrixXf V= esA.eigenvectors().transpose();
	struct matran Vt = createMatrix(cols,cols);
	for(int i=0;i<cols;i++){
		for(int j=0;j<cols;j++){
			Vt.coef[cols-i-1][j]=V(i,j);
		}
	}
	
	for(int i=0;i<cols;i++){
		for(int j=0;j<cols;j++){
			V(i,j)=Vt.coef[i][j];
			if(fabs(V(i,j))<10e-4)
			V(i,j)=0;
		}
	}

	

	MatrixXf matrixB = matrix*matrix.transpose();
	SelfAdjointEigenSolver<MatrixXf> esB(matrixB);
	MatrixXf U = esB.eigenvectors();
	
	for(int i=0;i<U.cols()/2;i++){
		temp =U.col(U.cols()-1-i);
		U.col(U.cols()-i-1)=U.col(i);
		U.col(i)=temp.col(0);
	}
	for(int i=0;i<min(sigma.rows(),sigma.cols());i++){
		if(sigma(i,i)!=0){
			temp=V.row(i);
			temp=temp.transpose();
			temp=matrix*temp/sigma(i,i);
			U.col(i)=temp.col(0);
		}
	}
	
	for(int i=0;i<rows;i++){
		for(int j=0;j<rows;j++){
			if(fabs(U(i,j))<10e-4)
			U(i,j)=0;
		}
	}
	cout.precision(4);
	cout <<"\nSingular value decomposition:\n";
	cout <<"\nMatrix S:\n"<<matrixA<<endl;
	cout <<"\nMatrix U:\n"<<U<<endl;
	cout <<"\nMatrix Sigma:\n"<<sigma<<endl;
	cout <<"\nMatrix V^T\n"<<V<<endl;
	cout <<"\nRetry: A = U * Sigma * V^T:\n";
	MatrixXf matrixC;
	if(V.cols()<U.cols()){
		MatrixXf Vn(rows,cols);
		for(int i=0;i<V.cols();i++){
			for(int j=0;j<U.cols();j++){
				if(j==U.cols()-1)
				Vn(i,j)=0;
				else Vn(i,j)=V(i,j);
			}
		}
		matrixC = U*sigma*Vn;
	}
	else{
		matrixC =U*sigma*V;
	}
	for(int i=0;i<cols;i++){
		for(int j=0;j<cols;j++){
			if(fabs(matrixC(i,j))<10e-4)
			matrixC(i,j)=0;
			cout << setw(7)<<setprecision(3)<<fixed<<matrixC(i,j)<<"\t";
		}
		cout << endl;
	}
}

int main()
{
	cout << "Enter number of row and cols : "; cin >>rows>>cols;
	input();
	outputMatrix();
	SVD();
	return 0;
}
