#include <iostream>

using namespace std;

class Point{
    int x, y;
    public:
        Point(int x, int y): x(x), y(y) {}
        Point(double x, double y): x(x), y(y) {}
        void setPoint(int x, int y){
            x = x;
            y = y;
        }

        void getPoint(){
            // cout << "x : " << x;
            // cout << " y : " << y;
            // cout << endl;
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "";
            cout << endl;
        }

        Point* operator+(const Point other){
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "  + ";
            cout << "(" << other.x;
            cout << ", " << other.y;
            cout << ")" << " = ";
            cout << "(" << (x + other.x);
            cout << ", " << (y + other.y);
            cout << ")" << "";
            cout << endl;
            return new Point((x + other.x), (y + other.y));
        }

        Point* operator-(const Point other){
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "  - ";
            cout << "(" << other.x;
            cout << ", " << other.y;
            cout << ")" << " = ";
            cout << "(" << (x - other.x);
            cout << ", " << (y - other.y);
            cout << ")" << "";
            cout << endl;
            return new Point((x - other.x), (y - other.y));
        }

        Point* operator/(const Point other){
            return new Point((x / other.x), (y / other.y));
        }

        Point* operator*(const Point other){
            return new Point((x * other.x), (y * other.y));
        }

        Point* operator+=(const Point other){
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "  + ";
            cout << "(" << other.x;
            cout << ", " << other.y;
            cout << ")" << " = ";
            cout << "(" << (x + other.x);
            cout << ", " << (y + other.y);
            cout << ")" << "";
            cout << endl;
            return new Point((x + other.x), (y + other.y));
        }
        Point* operator-=(const Point other){
            
            return new Point((x - other.x), (y - other.y));
        }
        Point operator-=(const int xx){
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "  - ";
            cout << "(" << xx;
            cout << ", " << 0;
            cout << ")" << " = ";
            cout << "(" << (x - xx);
            cout << ", " << (y - 0);
            cout << ")" << "";
            cout << endl;
            return Point((x - xx), (y));
        }
        void operator+=(const int xx){
            cout << "(" << x;
            cout << ", " << y;
            cout << ")" << "  + ";
            cout << "(" << xx;
            cout << ", " << 0;
            cout << ")" << " = ";
            cout << "(" << (x + xx);
            cout << ", " << (y + 0);
            cout << ")" << "";
            cout << endl;
            x + xx;
            // return Point((x + xx), (y));
        }

};

int main(){

    Point a = Point(2, -3);
    Point b = Point(1, 2);
    // Point* c = a * b;
    // Point* d = b / a;

    // c->getPoint();
    // d->getPoint();
    // Point *c =  b += a;
    a += 11;
    // b -= 1;
    // b.getPoint();
    // c->getPoint();

    
    return 0;
}