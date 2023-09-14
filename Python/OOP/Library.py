class Book :
    def __init__ (self, title, author, year) :
        self.title = title
        self.author = author
        self.year = year
        
    def display (self) :
        print(f"{self.title} - author: {self.author}, {self.year}")
        
class Library :
    def __init__ (self) :
        self.books = []
        
    def add_book (self, book) :
        self.books.append(book)
        
    def display (self) :
        for i in self.books :
            i.display()
            
a = Book("Harry Potter 1", "J.K Rowling", 1997)
b = Book("Harry Potter 2", "J.K Rowling", 1998)
c = Book("Harry Potter 3", "J.K Rowling", 1999)

fahasa = Library()
fahasa.add_book(a)
fahasa.add_book(b)
fahasa.add_book(c)
fahasa.display()