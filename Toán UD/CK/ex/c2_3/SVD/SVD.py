import numpy as np

def my_svd(A):
    # Tính AAT và ATA
    AAT = np.dot(A, A.T)
    ATA = np.dot(A.T, A)
    
    # Tính giá trị riêng và vectơ riêng
    eigenvalues_U, eigenvectors_U = np.linalg.eig(AAT)
    eigenvalues_V, eigenvectors_V = np.linalg.eig(ATA)
    
    # Sắp xếp giá trị riêng và vectơ riêng
    sorted_indices_U = np.argsort(eigenvalues_U)[::-1]
    sorted_indices_V = np.argsort(eigenvalues_V)[::-1]
    
    sorted_eigenvalues_U = eigenvalues_U[sorted_indices_U]
    sorted_eigenvectors_U = eigenvectors_U[:,sorted_indices_U]
    
    sorted_eigenvalues_V = eigenvalues_V[sorted_indices_V]
    sorted_eigenvectors_V = eigenvectors_V[:,sorted_indices_V]
    
    # Tính giá trị số ít và ma trận Sigma
    singular_values = np.sqrt(sorted_eigenvalues_U)
    Sigma = np.diag(singular_values)
    
    # Thêm các phần tử 0 vào Sigma để có kích thước mong muốn
    Sigma = np.pad(Sigma, ((0, A.shape[0] - Sigma.shape[0]), (0, A.shape[1] - Sigma.shape[1])), mode='constant')

    
    # Tạo thành U và V
    U = sorted_eigenvectors_U
    V = sorted_eigenvectors_V
    
    return U, Sigma, V

A = np.array([[1,2,0,0,0,0,0,0,0,0,0,0,0,0,0],
              [2,5,2,0,0,0,0,0,0,0,0,0,0,0,0],
              [0,2,5,2,0,0,0,0,0,0,0,0,0,0,0],
              [0,0,2,5,2,0,0,0,0,0,0,0,0,0,0],
              [0,0,0,2,5,2,0,0,0,0,0,0,0,0,0],
              [0,0,0,0,2,5,2,0,0,0,0,0,0,0,0],
              [0,0,0,0,0,2,5,2,0,0,0,0,0,0,0],
              [0,0,0,0,0,0,2,5,2,0,0,0,0,0,0],
              [0,0,0,0,0,0,0,2,5,2,0,0,0,0,0],
              [0,0,0,0,0,0,0,0,2,5,2,0,0,0,0],
              [0,0,0,0,0,0,0,0,0,2,5,2,0,0,0],
              [0,0,0,0,0,0,0,0,0,0,2,5,2,0,0],
              [0,0,0,0,0,0,0,0,0,0,0,2,5,2,0],
              [0,0,0,0,0,0,0,0,0,0,0,0,2,5,2],
              [0,0,0,0,0,0,0,0,0,0,0,0,0,2,5]])

U, Sigma, V = my_svd(A)

print("U:")
print(U)
print("\nSigma:")
print(Sigma)
print("\nVT:")
print(V.T)