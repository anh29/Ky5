from math import sqrt


def prime (a) :
    for i in range(2, int(sqrt(a)) + 1):
        if (a % i == 0):
            return 0
    return 1

lst = input("Input: ")
lst = lst.split(" ")

for i in range(len(lst)) :
    if (prime(int(lst[i]))) :
        print(i)
print("-1")