class Shape:
    def draw(self):
        print( "shape.base" )
    
    def __str__(self) -> str:
        return super().__str__(f"Shape")
    
class Rectangle(Shape):
    def draw(self):
        print( "shape.Rectangle" )
    
    def __str__(self) -> str:
        return super().__str__(f"Rectangle")

class Circle(Shape):
    def draw(self):
        print( "shape.Circle" )
    
    def __str__(self) -> str:
        return super().__str__(f"Circle")

class GetFactory:
    @staticmethod
    def getShape(type):
        print(type)
        if type == 'circle':
            return Circle()
        if type == 'rectangle':
            return Rectangle()
        else:
            pass

f = GetFactory.getShape("circle")
f.draw()
print(f)