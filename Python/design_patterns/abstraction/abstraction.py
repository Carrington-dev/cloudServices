from abc import ABCMeta, abstractmethod


class Vehicle(metaclass=ABCMeta):
    wheels = 0
    steering_wheel = 0


    @abstractmethod
    def drive(self):
        pass


class Car(Vehicle):
    # pass
    def drive(self):
        print("Use stearing wheel to turn left or right")

    def __str__(self) -> str:
        self.drive()
        return f"self.wheels = {self.wheels} \n{super().__str__()}"


car =  Car()
print(car)