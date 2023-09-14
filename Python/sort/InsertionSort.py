def input_list_int() :
    a = input("Input: ")
    list_input = a.split()  
    list_int = [int(x) for x in list_input]
    return list_int 

a = input_list_int()

for i in range(1, len(a)):
    last = a[i]
    j = i
    while((j > 0) & (a[j-1] > last)) :
        a[j] = a[j-1]
        j = j - 1
    a[j] = last
    
print(a)