#include <iostream>

using namespace std;

class Base{
    private:
        int x, y;
    public:
        Base(int x, int y): x(x), y(y){}

        void print(){
            cout << "x := " << x << endl;
            cout << "y := " << y << endl;
        }

        Base* printUs(){
            cout << "this := " << this << endl;

            return this;
        }

        Base operator+ (Base other){
            return Base(x+other.x, y + other.y);
        }

        Base operator- (Base other){
            return Base(x - other.x, y - other.y);
        }

        Base operator- (){
            return Base(-x, -y);
        }


        

};

void print(Base* b){
    cout << "this := " << &b << endl;
    
}

int main(){

    Base a(3, 7);
    a.print();
    a.printUs();

    Base d(3, 7);
    d.print();
    d.printUs();

    Base* b =  new Base(5, 9);
    b->print();
    b->printUs();
    cout << "this := " << &b << endl;

    Base* bb =  new Base(4, -9);
    bb->print();
    bb->printUs();
    cout << "this := " << &bb << endl;

    Base c =  a + d;
    // Base* c2 =  b->operator+(bb);
    c.print();

    print(b);

    return 0;
}