#include <iostream>

using namespace std;

class Point{
    private:
        int x, y, z = 0;
    public:
        Point(int x, int y): x(x), y(y){}
        Point operator()(int xx, int yy){
            x = xx;
            y= yy;
            // return Point(x, y);
            return *this;
        }
        Point operator()(int xx, int yy, int zz){
            x = xx;
            y = yy;
            z = zz;
            // return Point(x, y);
            return *this;
        }

        Point* operator->(){
            return this;
        }

        void print(){
            cout << "(" << x << ", " << y <<", " << z << ")" << endl;
        }



};

int main()
{
    Point p(0, 9);
    p.print();
    p(3, 6);
    p.print();
    p(-7, 16, 5);
    p->print();
    return 0;
}