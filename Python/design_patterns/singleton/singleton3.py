class Car:
    title = "Car"

    def __new__(sls):
        print(sls)
        if not hasattr(__class__, 'instance'):
            __class__.instance = super(Car, __class__).__new__(__class__)
        return sls
    
car1 = Car()
car2 = Car()
    
print(Car)
print(car1 == car2)
print(id(car1))
print(id(car2))