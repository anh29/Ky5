# Bài tập 7: Viết chương trình tìm nghiệm cho hệ phương trình thặng dư.

def extended_gcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        g, y, x = extended_gcd(b % a, a)
        return (g, x - (b // a) * y, y)

# tìm nghịch đảo module của a modulo m
def mod_inverse(a, m):
    g, x, y = extended_gcd(a, m)
    if g != 1:
        return None
    else:
        return x % m

def chinese_remainder_theorem(a_list, m_list):
    M = 1
    # tạo ra tích của tất cả các phần tử trong danh sách m_list
    for m in m_list:
        M *= m

    x = 0
    for i in range(len(a_list)):
        ai = a_list[i]
        mi = m_list[i]
        bi = M // mi
        bi_inverse = mod_inverse(bi, mi)
        x += ai * bi * bi_inverse

    return x % M

# tính tích của các phần tử trong danh sách
def product_of_list(lst):
    result = 1
    for element in lst:
        result *= element
    return result

# nhập dữ liệu từ người dùng và chuyển đổi thành các danh sách của các số nguyên.
a_list = [3, 5, 8, 7]
m_list = [5, 7, 11, 13]

solution = chinese_remainder_theorem(a_list, m_list)

print(f" x ≡ {solution} (mod {product_of_list(m_list)})")