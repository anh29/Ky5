import math as ma
import numpy as np
def multiple(A,B):
    return np.matmul(A,B)
def is_symmetric(matrix):
    B=np.zeros((len(matrix), len(matrix)))
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            B[i,j] = matrix[j,i]
    return np.allclose(matrix, B)

def is_square(matrix):
    return matrix.shape[0] == matrix.shape[1]

def is_positive_definite(A):
    M = np.zeros((len(A), len(A)), dtype=float)
    M1= np.zeros((len(A), len(A)), dtype=float)
    for k in range(n-2,-1,-1):
        for i in range(n):
            for j in range(n):
                if(i!=k):
                    if(i==j):
                        M[i,j]=1
                        M1[i,j]=1
                    else:
                        M[i,j]=0
                        M1[i,j]=0
                else:
                    M1[i,j]=A[k+1,j]
                    if(j==k) :M[i,j]=1/A[k+1,k]
                    else: M[i,j] = -A[k+1,j]/A[k+1,k]
        B=multiple(A,M)
        A=multiple(M1,B)

    PP=[1]
    for i in range(n):
        PP.append(-A[0,i])
    result1=np.roots(PP)
    result=np.array(result1)
    for i in range(len(result1)):
        if result1[i] <= 0 :
            return False
    return True
        
def Cholesky(matrix):
    result=np.zeros((len(matrix),len(matrix)))
    for j in range(len(matrix)):
        for i in range(j, len(matrix)):
            if i==j:
                sum=0
                for k in range(j):
                    sum+=result[i,k]**2
                result[i,j]=ma.sqrt(matrix[i,j]-sum)
            else:
                sum=0
                for k in range(j):
                    sum+=result[i,k]*result[j,k]
                result[i,j] = (1/result[j,j])*(matrix[i,j]-sum)
    return result
n=int(input("Nhập n: "))
A=np.zeros((n,n))
for i in range(n):
    for j in range(n):
        A[i,j]=float(input(f"Nhập A[{i+1},{j+1}]: "))
A1=A.T
for i in range(n):
    for j in range(n):
        print(A[i,j], end=' ')
    print()
print("Đối xứng")
for i in range(n):
    for j in range(n):
        print(A1[i,j], end=' ')
    print()

#Kiểm tra ma trận đối xứng
if (is_symmetric(A)):
    #Kiểm tra ma trận xác định dương
    if is_positive_definite(A):
        #Recode cholesky function and use Numpy library to check these result
        result=Cholesky(A)
        print("Ma trận phân rã theo phương pháp Cholesky là:\n", result, "\nNghịch đảo: \n", result.T)

    else:
        print("Ma trận này không xác định dương, không thực hiện phân rã Cholesky được!\n")
else: 
    print("Ma trận này không đối xứng, không thực hiện phân ra Cholesky được!\n")