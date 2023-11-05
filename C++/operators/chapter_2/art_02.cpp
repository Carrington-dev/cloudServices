#include <iostream>

using namespace std;

class Mark{
    int x;
    public:
        Mark(int x = 0): x{x}{}

        void getMark(){
            cout << "x = " << x << endl;
        }

        Mark operator--(){
            Mark m(*this);
            x -= 1;
            return m;
        }

        Mark operator++(int){
            Mark m(*this);
            x += 1;
            return m;
        }

        Mark operator--(int){
            Mark m(*this);
            x -= 1;
            return m;
        }

        Mark operator++(){
            Mark m(*this);
            x += 1;
            return m;
        }
};

int main()
{
    Mark m(123);
    m.getMark();
    (m--).getMark();
    m.getMark();
    // m.getMark();
    // --m;
    // m.getMark();
    // ++m;
    // m.getMark();
    return 0;
}