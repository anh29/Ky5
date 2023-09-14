
def swap(_list, i, j) :
    _list[i], _list[j] = _list[j], _list[i] #tuple unpacking
    
def input_list_int() :
    a = input("Input: ")
    list_input = a.split()  
    list_int = [int(x) for x in list_input]
    return list_int 