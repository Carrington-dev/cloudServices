#include <iostream>

using namespace std;

class Point{
    private:
        int *x, *y;
    public:
        Point(int xx = 0, int yy = 0): x(new int(xx)), y(new int(yy)) {}
        void print(){
            cout << "x := " << *x;
            cout << " y := " << *y;
            cout << endl;
            cout << this << endl;
            // cout << *this.x << endl;
        }

        Point& operator= (const Point& other){
            if(this != &other)
            {
                *x = *other.x;
                *y = *other.y;
            }

            return *this;
        }
};

int main(){
    Point A;
    Point B(2, -3);

    A.print();
    B.print();

    A = B;

    A.print();
    B.print();
    // cout << (&A) << endl;
    // cout << (&B) << endl;
    return 0;
}