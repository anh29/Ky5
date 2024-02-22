import numpy as np
from numpy import linalg as LA


A = np.array([[1,2,3],
              [0,2,5]])
U, S, V = LA.svd(A)

S = np.pad(S, ((0, A.shape[1] - S.shape[0]), (0, A.shape[0] - S.shape[1])), mode='constant')


print('A:\n' + str(A) + '\n')
print('U:\n' + str(U) + '\n')
print('Sigma:\n' + str(S) + '\n')
print('VT:\n' + str(V) + '\n')

print(U.dot(S))