#include <stdio.h>
#include <math.h>
#include <string.h>

const int MAX = 100;

void inputMatrix(int matrix[][MAX], int n) {
    printf("Enter elements for matrix: \n");

    for (int i = 0; i < n; i++) {
        printf("Input row [%d] of matrix: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

bool isSymmetric(int matrix[][MAX], int n)
{
    for (int i = 0; i < n; i++) 
	{
		for (int j = i+1; j < n; j++) 
		{
            if (i != j)
            {
            	if(matrix[i][j] != matrix[j][i])
            	{
            		return false;
				}
			}
			
        }
    }
    return true;
}

void multMatrices(int A[][MAX], float B[][MAX], int result[][MAX], int n)
{
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += (int)A[i][k] * B[k][j];
            }
        }
    }
}

int lowerTriangular(int matrix[][MAX], int lower[][MAX], int n) 
{
    memset(lower, 0, sizeof(lower));
    
	// Decomposing a matrix into Lower Triangular
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int sum = 0;

            if (j == i) // summation for diagonals
            {
                for (int k = 0; k < j; k++)
                    sum += pow(lower[j][k], 2);
                if (matrix[j][j] - sum < 0)
                {
                	printf("Matrix cannot be positive definite!");
                	return 0;
				}
                lower[j][j] = sqrt(matrix[j][j] - sum);
            } else {
                // Evaluating L(i, j) using L(j, j)
                for (int k = 0; k < j; k++)
                    sum += (lower[i][k] * lower[j][k]);
                lower[i][j] = (matrix[i][j] - sum) / lower[j][j];
            }
        }
    }
    return 1;
}

void Cholesky_LLt(int matrix[][MAX], int n) {

    int lower[MAX][MAX];
	printf("\nCholesky LLt.\n");
    
    if (lowerTriangular(matrix, lower, n))
    {
    	// Displaying Lower Triangular and its Transpose
	    printf("%6s%30s\n", "L", "L^t");
	    for (int i = 0; i < n; i++) {
	        // Lower Triangular
	        for (int j = 0; j < n; j++)
	            printf("%6d\t", lower[i][j]);
	        printf("\t");
	
	        // Transpose of Lower Triangular
	        for (int j = 0; j < n; j++)
	            printf("%6d\t", lower[j][i]);
	        printf("\n");
	    }
	}
}

void Cholesky_LDLt(int matrix[][MAX], int n) {
    int lower[MAX][MAX], K[MAX][MAX], D[MAX][MAX];
    float S1[MAX][MAX];
    
    memset(S1, 0, sizeof(S1));
    memset(K, 0, sizeof(K));
    memset(D, 0, sizeof(D));

	printf("\nCholesky LDLt.\n");
    
	if (lowerTriangular(matrix, lower, n))
    {
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++)
	        {
	            if (i==j)
	            {
	            	S1[i][i] = (float)1 / lower[i][i];
	            	D[i][i] = pow(lower[i][i], 2);
				}
	        }
		}
    	multMatrices(lower, S1, K, n);
    	
    	printf("%6s%30s%34s\n", "K", "D", "K^t");
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++)
	            printf("%6d\t", K[i][j]);
	        printf("\t");
	        
		for (int j = 0; j < n; j++)
	            printf("%6d\t", D[i][j]);
	        printf("\t");
	
	        // Transpose of Lower Triangular
	        for (int j = 0; j < n; j++)
	            printf("%6d\t", K[j][i]);
	        printf("\n");
	    }
	}
}

int main() {
    int n;
	printf("Input n (2,3,4): "); scanf("%d", &n);
	
	int matrix[n][MAX];
	inputMatrix(matrix, n);
	
	if (isSymmetric(matrix, n) == false)
	{
		printf("Matrix can not be positive definite (not symmetric).");
	} else
	{
		Cholesky_LDLt(matrix, n);
	}
 
    return 0;
}

