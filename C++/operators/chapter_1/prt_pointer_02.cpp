#include <iostream>

using namespace std;

int main()
{

    string* s  =  new string("Carrington");
    cout << "string s " << s << endl << endl;
    cout << "string *s " << *s << endl << endl;
    cout << "string &s " << &s << endl << endl;
    cout << "string new string() " << new string("Carrington") << endl << endl;

    return 0;
}