# Bài tập 2: Tìm số hoàn hảo từ 1 đến n.

def check_perfect(n):
    sum = 0
    for i in range(1, n):
        if (n % i) == 0:
            sum += i
    if sum == n:
        return True
    else:
        return False

def find_perfect_numbers(n):
    rs = []
    for i in range(1, n):
        if check_perfect(i):
            rs.append(i)
    return rs

n = int(input("n = "))

perfect_numbers_list = find_perfect_numbers(n)

print(perfect_numbers_list)