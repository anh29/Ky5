import numpy as np

eps = 1e-5

def matrix_transpose(a):
    return a.T

def multi_one_row(s, a, b, r, ans):
    c = b[:, r]
    d = (1.0 / s) * np.dot(a, c)
    ans[:, r] = d

def gauss_jordan(a):
    n = len(a)
    ans = np.zeros(n)
    
    for i in range(n):
        if a[i, i] == 0:
            for j in range(i + 1, n):
                if a[j, i] != 0:
                    a[i], a[j] = a[j].copy(), a[i].copy()
        if a[i, i] == 0:
            ans[i] = 1
            continue
        for j in range(i + 1, n):
            factor = a[j, i] / a[i, i]
            a[j] -= factor * a[i]
    
    for i in range(n - 1, 0, -1):
        if a[i, i] == 0:
            continue
        S = 0
        for j in range(i + 1, n):
            S -= a[i, j] * ans[j]
        ans[i] = S / a[i, i]
    
    return ans

def svd_solve(A):
    A_T = matrix_transpose(A)
    S = np.dot(A_T, A)
    eigenvalues, eigenvectors = np.linalg.eig(S)
    
    m, n = A.shape
    lambda_S = np.diag(eigenvalues)
    V = eigenvectors
    Sigma = np.zeros((m, n))
    
    possible = min(m, n, lambda_S.shape[0])
    for i in range(possible - 1, 0, -1):
        for j in range(i):
            if lambda_S[j, j] < lambda_S[j + 1, j + 1]:
                lambda_S[j, j], lambda_S[j + 1, j + 1] = lambda_S[j + 1, j + 1], lambda_S[j, j]
                V[:, j], V[:, j + 1] = V[:, j + 1].copy(), V[:, j].copy()
    
    for i in range(possible):
        Sigma[i, i] = np.sqrt(lambda_S[i, i]) if abs(lambda_S[i, i]) >= eps else 0
    
    U = np.zeros((m, m))
    for i in range(m):
        if i < possible and Sigma[i, i] != 0:
            multi_one_row(Sigma[i, i], A, V, i, U)
        else:
            U[:, i] = gauss_jordan(U)
    
    print("U =")
    print(U)
    print("Sigma =")
    print(Sigma)
    print("V^T =")
    print(V)
    print("Product of U, Sigma, and V^T for result verification:")
    print(np.dot(np.dot(U, Sigma), V.T))

if __name__ == "__main__":
    m = int(input("Enter the number of rows: "))
    n = int(input("Enter the number of columns: "))
    print("Enter the matrix:")
    a = np.zeros((m, n))
    for i in range(m):
        a[i] = list(map(float, input().split()))
    
    print("Result:")
    svd_solve(a)