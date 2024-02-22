import numpy as np

def row_operations(matrix, row1, row2, factor):
    matrix[row1] -= factor * matrix[row2]

def inverse(matrix):
    n = len(matrix)
    augmented_matrix = np.hstack((matrix, np.eye(n)))

    for i in range(n):
        pivot = augmented_matrix[i, i]
        if pivot == 0:
            return "Ma trận không có nghịch đảo vì định thức bằng 0."

        augmented_matrix[i] /= pivot

        for j in range(n):
            if i != j:
                factor = augmented_matrix[j, i]
                row_operations(augmented_matrix, j, i, factor)

    inv_matrix = augmented_matrix[:, n:]
    return inv_matrix

A = np.array([[4, 2, 5],
              [7, 6, 3],
              [1, 9, 8]])

inv_A = inverse(A)

print("Ma trận nghịch đảo của A:")
print(inv_A)
