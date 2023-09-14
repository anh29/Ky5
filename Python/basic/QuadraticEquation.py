# Phuong trinh bac 2
from math import sqrt


a = float(input())
b = float(input())
c = float(input())

dental = b**2 - 4*a*c

if (dental > 0):
  x1 = (-b + sqrt(dental))/(2*a)
  x2 = (-b - sqrt(dental))/(2*a)
  print("The equation has two real solution! x1 =", x1, ",x2 =", x2)
elif (dental == 0):
  x = -b/(2*a)
  print("The equation has one real solution! x =", x)
else:
  print("The equation has no solution!")
