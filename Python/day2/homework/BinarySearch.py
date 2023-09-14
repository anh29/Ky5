
def input_list_int() :
    a = input("Input: ")
    list_input = a.split()  
    list_int = [int(x) for x in list_input]
    return list_int 

def binary(lst, low, high, x) :
    if low <= high :
        mid = int((high + low)/2)
        print(mid)
        if lst[mid] == x:
            return mid
        elif x < lst[mid]:
            return binary(lst, low, mid - 1, x)
        else :
            return binary(lst, mid + 1, high, x)
    return -1 
        
a = input_list_int()
x = input("Find: ")
print(binary(a, 0, len(a) - 1, int(x)))
