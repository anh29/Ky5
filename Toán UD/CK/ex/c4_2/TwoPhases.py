#%%
import numpy as np

def first_negative_cost(vector_c):
    n = len(vector_c)
    j = 0
    while j < n:
        if vector_c[j] >= 0:
            j += 1
        else:
            return j

def find_the_first_positive(vector):
    n = len(vector)
    j = 0
    while j < n:
        if vector[j] <= 0:
            j += 1
        else:
            return j

def lowest_positive_ratio(vector_xj, vector_b):
    ratios = vector_b / vector_xj
    ratios_sort = np.sort(ratios)
    result_sort = np.where(ratios_sort >= 0)
    result = np.where(ratios == ratios_sort[result_sort[0][0]])
    return result[0][0]

def row_to_np_array(matrix_A, row):
    n, m = np.shape(matrix_A)
    vect = np.zeros(m)
    for i in range(m):
        vect[i] = matrix_A[row, i]
    return vect

def col_to_np_array(matrix_A, col):
    n, m = np.shape(matrix_A)
    vect = np.zeros(n)
    for i in range(n):
        vect[i] = matrix_A[i, col]
    return vect

def is_unbounded(table):
    return np.any(np.all(table <= 0, axis=0))

def simplex(table):
    iterations = 0
    table = identityInsideMatrix(table)
    while np.any(table[-1, :-1] < 0) and iterations < 10000:
        vec_c = row_to_np_array(table, -1)
        vec_b = col_to_np_array(table, -1)

        j = first_negative_cost(vec_c[:-1])

        col_j = col_to_np_array(table, j)

        i = lowest_positive_ratio(col_j[:-1], vec_b[:-1])
        table[i, :] /= table[i, j]
        for k in range(table.shape[0]):
            if k != i:
                table[k, :] -= table[k, j] * table[i, :]
        iterations += 1
        if is_unbounded(table):
            return table
    return table

def canonVector(vector, n):
    if len(vector) == 0:
        return -99
    i = 0
    sum = 0
    pos = -1
    while i < n:
        sum += abs(vector[i])
        if vector[i] == 1:
            pos = i
        i += 1
    if sum == 1:
        return pos
    else:
        return -1

def turnToCanonColumn(matrix, row, column):
    matrix[row, :] /= matrix[row, column]
    for i in range(matrix.shape[0]):
        if i != row:
            matrix[i, :] -= matrix[row, :] * matrix[i, column]
    return matrix


def identityInsideMatrix(table):
    n, m = table.shape
    i = 0
    j = 0
    canonColumns = []
    canonList = []
    missingCanonVectors = []

    while j < m:
        pos = canonVector(table[:, j], n - 1)
        if pos >= 0:
            canonList.append(pos)
            canonColumns.append(j)
        j += 1

    aux = list(range(0, n - 1))
    missingCanonVectors = [x for x in aux if x not in canonList]
    i = 0
    while i < m - 1 and len(missingCanonVectors) != 0:
        if i not in canonColumns:
            newCanonPosition = missingCanonVectors.pop(0)
            turnToCanonColumn(table, newCanonPosition, i)
        i += 1
    for canonVectorVar in canonColumns:
        if table[-1, canonVectorVar] != 0:
            pos = canonVector(table[:, canonVectorVar], n - 1)
            table[-1, :] -= table[pos, :] * table[-1, canonVectorVar]
    return table

def canonVectorAndPosition(matrix):
    n, m = matrix.shape
    i = 0
    j = 0
    list = []
    for j in range(m):
        canonVecVar = canonVector(matrix[:, j], n + 1)
        if canonVecVar >= 0:
            list.append([canonVecVar, j])
    return list

np.seterr(divide="ignore", invalid="ignore")
#%%
def generate_simplex_table_first_phase(matrix_A, vector_b):
    n, m = np.shape(matrix_A)
    table_0 = np.zeros((n + 1, m + n + 1))
    for i in range(n):
        for j in range(m):
            table_0[i, j] = matrix_A[i, j]
    for i in range(n):
        table_0[i, m + i] = 1
    for i in range(n):
        table_0[i, -1] = vector_b[i]
    for i in range(n):
        table_0[-1, m + i] = 1
    return table_0

#%% Tests
A = np.matrix([[1, 2], [1, 2]])
b = np.array([7, 8])

generate_simplex_table_first_phase(A, b)
#%%
def from_first_phase_generate_simplex_table_second_phase(final_table_1p, vector_c):
    n1P, m1P = np.shape(final_table_1p)
    n, m = n1P - 1, m1P - n1P
    table_0 = np.zeros((n + 1, m + 1))
    for i in range(n):
        for j in range(m):
            table_0[i, j] = final_table_1p[i, j]
    for i in range(n):
        table_0[i, -1] = final_table_1p[i, -1]
    for i in range(m):
        table_0[-1, i] = vector_c[i]
    return table_0

#%% Tests
A = np.matrix(
    [
        [1.0, 0.0, 1.0, 2.5, 0.0, 7.0],
        [0.0, 1.0, 0.0, 1.0, 1.5, 8.0],
        [0.0, 0.0, 0, 5.0, 5.0, 0.0],
    ]
)
c = [1, 2, 3]
from_first_phase_generate_simplex_table_second_phase(A, c)
#%%
def canonVectorAndPosition(matrix):
    n, m = matrix.shape
    i = 0
    j = 0
    list = []
    for j in range(m):
        canonVecVar = canonVector(matrix[:, j], n - 1)
        if canonVecVar >= 0:
            list.append([j, canonVecVar])
    return list

def get_solutions_simplex(final_table):
    n2P, m2P = np.shape(final_table)
    n, m = n2P - 1, m2P - 1
    vector_sol = np.zeros(m)
    pos_solutions = canonVectorAndPosition(final_table)
    min_func_obj = -final_table[n, m]
    for pos in pos_solutions:
        vector_sol[pos[0]] = final_table[pos[1], -1]
    return vector_sol, min_func_obj

def TwoPhases(matrix_A, vector_b, vector_c):
    table_0_1p = generate_simplex_table_first_phase(matrix_A, vector_b)
    final_table_1p = simplex(table_0_1p)

    if is_unbounded(final_table_1p):
        print("The problem is unbounded")
        print("The problem has no feasible solution")
        return
    if abs(final_table_1p[-1][-1]) >= 10**-5:
        print("The problem has no feasible solution")
        return

    table_0_2p = from_first_phase_generate_simplex_table_second_phase(
        final_table_1p, vector_c
    )
    final_table_2p = simplex(table_0_2p)
    if is_unbounded(final_table_2p):
        print("the problem is unbounded")
        print("The problem has no feasible solution")
        return
    sol, z_op = get_solutions_simplex(final_table_2p)
    print("The solution of the first LPP is: ")
    for i in range(len(sol)):
        print("Variable", i + 1, "is:", sol[i])
    print("With the value of the objective function:", z_op)
    return

B = np.array([[4.0, 3.0, 4.0], [4.0, 1.0, 6.0]])
b_vector = np.array([4.0, 5.0])
c_vector = np.array([-4, 3.0, 1.0])
print("Sol. Ejercicio B clase Modelado: ")
TwoPhases(B, b_vector, c_vector)
# %%
