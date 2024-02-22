def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = extended_gcd(b % a, a)
        return (g, x - (b // a) * y, y)

def diophantine_solution(a, b, c):
    # Sử dụng thuật toán Euclid mở rộng để tìm g = gcd(a, b).
    g, x, y = extended_gcd(a, b)
    # Nếu c không chia hết cho d, thì phương trình không có nghiệm.
    if c % g == 0:
        # Tìm nghiệm của phương trình.
        x0 = x * (c // g)
        y0 = y * (c // g)
        return x0, y0
    else:
        return None

a = int(input("Nhập a: "))
b = int(input("Nhập b: "))
c = int(input("Nhập c: "))

solution = diophantine_solution(a, b, c)

if solution is not None:
    x, y = solution
    print(f"Nghiệm của phương trình {a}x + {b}y = {c} là (x, y) = ({x}, {y})")
else:
    print(f"Phương trình {a}x + {b}y = {c} không có nghiệm nguyên.")