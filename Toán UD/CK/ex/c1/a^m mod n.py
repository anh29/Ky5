# Bài tập 5: viết chương trình tính a^m mod n

# Tính toán thuật toán Euclid mở rộng, trả về ước chung lớn nhất và các hệ số x và y.
def extended_gcd(a, b):
        if a == 0:
            return (b, 0, 1)
        else:
            # Gọi đệ quy hàm extended_gcd với các đối số mới b % a và a.
            g, y, x = extended_gcd(b % a, a)
            return (g, x - (b // a) * y, y)
        
def mod_inverse(a, m):    
    g, x, y = extended_gcd(a, m)
    if g != 1:
        # Nếu g khác 1, trả về None (do không có nghịch đảo module).
        return None
    else:
        return x % m

a = int(input("a = "))
m = int(input("m = "))
n = int(input("n = "))

inverse = mod_inverse(a, n)
if inverse is not None:
    print(f"Nghịch đảo module {n} của {a} là {inverse}")
else:
    print(f"{a} không có nghịch đảo module {n}")
