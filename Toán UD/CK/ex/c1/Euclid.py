# Bài tập 4: Cài đặt thuật toán Euclid

def euclidean_gcd(a, b):
    # Kiểm tra nếu b bằng 0. Nếu điều này đúng, thì ước chung lớn nhất là a.
    if (b == 0):
        return a
    # Nếu b khác 0, thì đệ quy gọi lại hàm euclidean_gcd. Lúc này, a trở thành b và b trở thành a % b (phần dư của a chia b).
    return euclidean_gcd(b, a % b)

a = int(input("a = "))
b = int(input("b = "))

gcd = euclidean_gcd(a, b)

print(f"Ước chung lớn nhất của {a} và {b} là {gcd}")
