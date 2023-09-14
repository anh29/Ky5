class Computer:

    def __init__(self):
        self.__maxPrice = 900 # private

    def sell(self):
        print("Giá bán sản phẩm là: {}".format(self.__maxPrice))

    def setMaxPrice(self, price):
        self.__maxPrice = price

c = Computer()
c.sell()

# thay đổi giá:
c.__maxPrice = 1000
c.sell()

# sử dụng hàm để thay đổi giá:
c.setMaxPrice(1000)
c.sell()