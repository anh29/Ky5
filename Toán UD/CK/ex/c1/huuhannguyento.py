# Bài tập 1: Viết chương trình nhập vào n và đưa ra danh sách tích hữu hạn của 
# các nguyên tố.

def product_list(n):
    i = 2
    listNumbers = []
    while n > 1:
        if n % i == 0: # Kiểm tra xem n có chia hết cho i hay không (điều kiện để i là thừa số nguyên tố của n).
            n = int(n / i)
            listNumbers.append(i)
        else:
            i = i + 1
    if len(listNumbers) == 0:
        listNumbers.append(n) # Nếu listNumbers không chứa phần tử nào, thêm n vào danh sách. Điều này xảy ra khi n là số nguyên tố.
    return listNumbers
 
n = int(input("n = "))
product_listnumber = product_list(n)

def format_as_powers(numbers):
    formatted = []
    for num in set(numbers): # Duyệt qua từng phần tử duy nhất trong danh sách numbers.
        power = numbers.count(num) # Đếm số lượng lần xuất hiện của num trong danh sách numbers. Đây sẽ là số mũ.
        formatted.append(f"{num}^{power}") # Thêm chuỗi biểu diễn thừa số vào danh sách formatted.
    return " x ".join(formatted) # Trả về chuỗi kết quả bằng cách nối các chuỗi trong danh sách formatted bằng ký tự " x ".

formatted_result = format_as_powers(product_listnumber)

print(formatted_result)

# Input n = 572
# Kết quả: 2^2 x 11^1 x 13^1