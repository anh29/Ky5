
def input_list_int() :
    a = input("Input: ")
    list_input = a.split()  
    list_int = [int(x) for x in list_input]
    return list_int 

def min(lst) :
    min = lst[0]
    for i in range(len(lst)) :
        if lst[i] < min :
            min = lst[i]
    return min
    
a = input_list_int()
b = []
for i in range(len(a)) :
    m = min(a)
    b.append(m)
    a.remove(m)

print(b)
    