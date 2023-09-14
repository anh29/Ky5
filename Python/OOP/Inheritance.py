# parent class
class Person (object) :
    # __init__ is known as the constructor
    def __init__ (self, name, id) :
        self.name = name
        self.id = id
        
    def display (self) :
        print('Name is ' + self.name)
        print('ID: ' , self.id)
        
    def details (self) :
        pass
    
# child class
class Employee (Person) :
    def __init__(self, name, id, salary, post):
        super().__init__(name, id)
        
        self.salary = salary
        self.post = post
        
    def details(self):
        print('--------Details---------')
        print('Name is ' + self.name)
        print('ID: ' , self.id)
        print('Post: ' + self.post)
        print('Salary: ' , self.salary)
        
a = Employee('Rahul', 886012, 200000, "Intern")

a.display()
a.details()