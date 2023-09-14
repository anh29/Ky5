from math import sqrt

check = 0
a = input("Input: ")
a = int(a)
for i in range(2, int(sqrt(a)) + 1):
    if (a % i == 0):
        print("No")
        check = 1
        break
if (check != 1):
    print("Yes")
