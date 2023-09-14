a = input("dd/mm/yyyy ")
birth = a.split('/')

year = 2023
age = year - int(birth[2])

print("Your age: ", age)