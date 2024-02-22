
#include <iostream> 
#include <iomanip> 
#include <Eigen/Dense> 
#include <Eigen/Eigenvalues> 
using namespace Eigen; 
using namespace std; 
float data[100000]; 
int rows, cols; 
 
struct mat 
{ 
	int sd, sc; 
	float coef[100][100]; 
}; 
 
struct mat createMatrix(int m, int n) 
{ 
	struct mat A; 
	int i, j; 
	 
	A.sd = m; 
	A.sc = n; 
	for (i = 0; i < m; i++) 
	  	for (j = 0; j < n; j++) 
	   		A.coef[i][j] = 0; 
	 
	return A; 
} 
 
int Enter() 
{ 
	cout << "Enter number of row and column: "; 
	cin >> rows >> cols; 
	cout << "Enter Matrix A: " << endl; 
	for (int i = 0; i < rows * cols; i++) 
	{ 
	  	cin >> data[i]; 
	} 
} 
 
void SVD() 
{ 
	MatrixXf matrix(rows, cols); 
	 	for (int i = 0; i < rows; i++) 
		{ 
		  	for (int j = 0; j < cols; j++) 
		  	{ 
		   	matrix(i, j) = data[i * cols + j]; 
		  	} 
		} 
	 
	struct mat sig = createMatrix(rows, cols); 
	MatrixXf sigma(rows, cols); 
	MatrixXf matrixA = matrix.transpose() * matrix; //A_T*A
	 
	SelfAdjointEigenSolver<MatrixXf> esA(matrixA); 
	int k = 0; 
	VectorXf temp = esA.eigenvalues(); //temp: gia tri rieng
	 
	for (int i = 0; i < temp.size(); i++) 
	{ 
  		if (fabs(temp[i]) < 10e-4) 
   			temp[i] = 0; 
  		temp[i] = sqrt(temp[i]); 
  		sig.coef[temp.size() - i - 1][temp.size() - i - 1] = temp[i]; 
	} 
	 
	MatrixXf V = esA.eigenvectors().transpose(); 
	struct mat Vt = createMatrix(cols, cols); 
	
	for (int i = 0; i < cols; i++) 
	{ 
	  	for (int j = 0; j < cols; j++) 
	  	{ 
	   		Vt.coef[cols - i - 1][j] = V(i, j); 
	  	} 
	} 
	 
	MatrixXf matrixB = matrix * matrix.transpose(); 
	SelfAdjointEigenSolver<MatrixXf> esB(matrixB); 
	MatrixXf U = esB.eigenvectors(); 
	 
	for (int i = 0; i < U.cols() / 2; i++) 
	{ 
	  	temp = U.col(U.cols() - i - 1); 
	  	U.col(U.cols() - i - 1) = U.col(i); 
	  	U.col(i) = temp.col(0); 
	} 
 
	for (int i = 0; i < cols; i++) 
	{ 
		for (int j = 0; j < cols; j++) 
		{ 
		   V(i, j) = Vt.coef[i][j]; 
		   if (fabs(V(i, j)) < 10e-4) 
		    V(i, j) = 0; 
		} 
	} 
 
	for (int i = 0; i < rows; i++) 
	{ 
		for (int j = 0; j < cols; j++) 
		{ 
		    sigma(i, j) = sig.coef[i][j]; 
		    if (fabs(sigma(i, j)) < 10e-4) 
			sigma(i, j) = 0; 
		} 
	} 
 
	for (int i = 0; i < min(sigma.rows(), sigma.cols()); i++) 
	{ 
		if (sigma(i, i) != 0) 
		{ 
		   temp = V.row(i); 
		   temp = temp.transpose(); 
		   temp = matrix * temp / sigma(i, i); 
		   U.col(i) = temp.col(0); 
		} 
	} 
	for (int i = 0; i < rows; i++) 
	{ 
		for (int j = 0; j < rows; j++) 
		{ 
			if (fabs(U(i, j)) < 10e-4) 
			U(i, j) = 0; 
		} 
	} 
	cout << "\nSVD Decomposition A = U * Sigma * V^T :" << endl; 
	cout << setprecision(5) << fixed; 
	cout << "\nU\n\n" << U << endl; 
	cout << "\nSigma\n\n" << sigma << endl; 
	cout << "\nV^T\n\n" << V << endl; 
	cout << "Thu lai" << endl;
	///////////
	MatrixXf mtKQ ;
	if (V.cols() < U.cols()){
		MatrixXf mtVnew(rows, cols);
		for (int i = 0; i < V.cols(); i++) 
		{ 
			for (int j = 0; j < U.cols(); j++) 
			{ 
				if (j == U.cols()-1) 
					mtVnew(i, j) = 0; 
				else mtVnew(i, j) = V(i,j);
			} 
		} 
		mtKQ = U*sigma*mtVnew;
	}
	else 	mtKQ = U*sigma*V; 

	for (int i = 0; i < cols; i++) 
	{ 
	  	for (int j = 0; j < cols; j++) 
	  	{ 
		  	if (fabs(mtKQ(i, j)) < 10e-4) 
				mtKQ(i, j) = 0; 
	   		cout << setw(7) << setprecision(4) << fixed << mtKQ(i,j) <<  "\t";
	  	} 
	  	cout << endl;
	} 
} 
 
int main() 
{ 
	 Enter(); 
	 SVD(); 
	 
	 return 0; 
} 
