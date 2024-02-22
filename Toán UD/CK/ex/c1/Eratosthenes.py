# Bài tập 3 : viết chương trình mô phỏng ràng Eratosthenes. Lập bảng tìm được số nguyên tố với n = 100.000.0000

def sieve_of_eratosthenes(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False

    p = 2
    while p**2 <= n:
        if is_prime[p]:
            for i in range(p**2, n + 1, p):
                is_prime[i] = False
        p += 1

    primes = [i for i in range(2, n + 1) if is_prime[i]]
    return primes

n = 100
prime_numbers = sieve_of_eratosthenes(n)

print(prime_numbers)