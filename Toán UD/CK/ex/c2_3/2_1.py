import numpy as np

def determinant(matrix):
    return np.linalg.det(matrix)

def cofactor(matrix, i, j):
    minor = np.delete(np.delete(matrix, i, axis=0), j, axis=1)
    return (-1) ** (i + j) * determinant(minor)

def adjugate(matrix):
    n = len(matrix)
    adj = np.zeros((n, n))
    for i in range(n):
        for j in range(n):
            adj[i, j] = cofactor(matrix, j, i)
    return adj

def inverse(matrix):
    det = determinant(matrix)
    if det == 0:
        return "Ma trận không có nghịch đảo vì định thức bằng 0."
    adj = adjugate(matrix)
    inv = adj / det
    return inv

A = np.array([[4, 2, 5],
              [7, 6, 3],
              [1, 9, 8]])

inv_A = inverse(A)

print("Ma trận nghịch đảo của A:")
print(inv_A)
