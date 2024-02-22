# Viết chương trình thực hiện phân rã Cholesky

# Mô tả:
# 1. Đầu tiên, kiểm tra ma trận đầu vào A xem có thể sử dụng phân rã Cholesky không. Điều này đòi hỏi ba điều kiện:
# A phải là ma trận vuông.
# A phải là ma trận đối xứng.
# A phải là ma trận xác định dương.
# → Nếu A không thoả mãn điều kiện nào, thông báo "Không thể áp dụng phân rã Cholesky cho A" và kết thúc chương trình.
# Nếu A đáp ứng tất cả các điều kiện, ta tiến hành bước tiếp theo.

# 2. Khởi tạo ma trận L với kích thước bằng với A, trong đó tất cả các phần tử đều khởi tạo là 0.

# 3. Dùng hai vòng lặp để điều chỉnh từng phần tử của ma trận L:
# Đối với mỗi j từ 1 đến n:
# 	Với mỗi i từ j đến n:
# 		Nếu i = j, tính L[i,j] = căn bậc hai của (A[i,j] – Tổng của (L[i,k])^2) với k chạy từ 1 đến j-1.
# 		Nếu i ≠ j, tính L[i,j] = (A[i,j] – Tổng của (L[i,k] * L[j,k])) chia cho L[j,j] với k chạy từ 1 đến j – 1.

# 4. Nhân L với ma trận chuyển vị của L để tạo thành A.

import numpy as np

# Kiểm tra ma trận có vuông không
def is_square_matrix(matrix):
    num_rows = len(matrix)
    num_cols = len(matrix[0])
    return num_rows == num_cols

# Kiểm tra ma trận có đối xứng không
def is_symmetric(matrix):
    # Nếu không vuông thì không cần xét tiếp
    if not is_square_matrix(matrix):
        return False
    
    # Tạo ma trận chuyển vị
    transpose = np.transpose(matrix)
    # Nếu ma trận chuyển vị của ma trận vuông bằng chính nó thì đây là ma trận đối xứng
    return np.array_equal(matrix, transpose)

# Kiểm tra ma trận xác định dương
def is_positive_definite_eigenvalues(matrix):
    # Lấy các giá trị riêng và bỏ qua các vector riêng
    eigenvalues, _ = np.linalg.eig(matrix)
    # Kiểm tra tất cả các giá trị riêng có > 0 hay không
    return all(eigenvalues > 0)

def cholesky(A):
    n = len(A)
    # Tạo ma trận L ban đầu
    L = np.zeros((n, n))

    for j in range(n):
        for i in range(j, n):
            sumk = 0
            for k in range(j):
                # Lấy tổng theo công thức
                sumk += L[i,k] * L[j,k]
            
            # Nếu i = j thì dùng công thức thứ nhất ngược lại thì công thức thứ hai
            if i == j:
                L[i,j] = np.sqrt(A[i,j] - sumk)
            else:
                L[i,j] = (A[i,j] - sumk) / L[j,j]

    return L

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
print("Ma trận A: \n", A)

if not is_square_matrix(A):
    print("A không phải ma trận vuông")
elif not is_symmetric(A):
    print("A không phải ma trận đối xứng")
elif not is_positive_definite_eigenvalues(A):
    print("A không phải ma trận xác định dương")
else:
    L = cholesky(A)
    print("\nMa trận L: \n", L)
    
    LT = cholesky(A).T
    print("\nMa trận L.T: \n", LT)

    LLT = np.dot(L, L.T)
    print("\nLLT: \n", LLT)
    