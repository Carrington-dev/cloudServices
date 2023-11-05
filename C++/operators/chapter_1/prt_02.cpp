#include <iostream>

using namespace std;

class Base{
    private:
        int a[2] = {0, 0};
    public:
        int x, y;
        Base(int x, int y): x(x), y(y){
            a[0] = x;
            a[1] = y;
        }

        void print(){
            cout << "x := " << x << "\t y := " << y << endl;
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

        Base operator-- (){
            return Base(x, y);
        }

        int& operator[] (int x){
            if(x == 0)
                return a[0];
            if(x == 1)
                return a[1];
            else
            {
                throw std::out_of_range("Index out of bounds");
                exit(0);
            }
        }


        

};

void print(Base* b){
    cout << "this := " << &b << endl;

    
}

int main(){

    Base a(3, 7);
    a.print();

    Base b =  -----a;
    b.print();

    // int c[] =  {3, 5, 6};
    // Base c_bases[] =  {a, b, a+b, -a, -b};
    // cout << "this c[1] := " << c_bases[1].x << endl;
    cout << "this a[0] := " << a[0] << endl;
    cout << "this a[1] := " << a[1] << endl;
    cout << "this a[4] := " << a[5] << endl;
    


   

    return 0;
}