class Car(object):
    title = f"Toyota"
    model = f"C-HR"
    year = f"2024"

    def __init__(self, title, model, year):
        # print("self =", self)
        self.title = f"{title}"
        self.model = f"{model}"
        self.year = f"{year}"
    
    
    def __new__(cls, title, model, year):
        # print("cls =", cls)
        if not hasattr(cls, 'instance'):
            cls.instance = super(Car, cls).__new__(cls)
        return cls.instance

    @classmethod
    def print(cls):
        print("cls =", cls)
    
    # @staticmethod
    # def getMe():
    #     return f"{__class__.title} - {__class__.model} - {__class__.year}"

    # @staticmethod
    @classmethod
    def getMe(cls):
        return f"{cls.title} - {cls.model} - {cls.year}"

    
    def __str__(self):
        # self.print()
        return f"{self.title} - {self.model} - {self.year}"
    

car1 = Car("Toyota", "C-HR", 2023)
car2 = Car("Toyota", "Corolla", 2023)
car3 = Car("Toyota", "Mawe", 2023)
# car1 = Car()
# car2 = Car()
# car3 = Car()

# print("class", Car)
print(Car.getMe())
# print(car1)
# print(car2)
# car3.model = "Corrola"
# print(car1)
# print(car2)


# print(car1 == car2)