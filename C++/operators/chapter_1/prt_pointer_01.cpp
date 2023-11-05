#include <iostream>

using namespace std;

int main(){
    string name = "Carrington";
    string* string_ptr = &name;

    cout << "Name " << name << endl;
    cout << "Name pointer* " << string_ptr << endl;
    cout << "Name memory address* " << &name << endl;
    cout << "Pointer value " << *string_ptr << endl;

    *string_ptr =  "Mulalo carrington Muleya (changed)";

    cout << "Name " << name << endl;
    cout << "Name pointer* " << string_ptr << endl;
    cout << "Name memory address* " << &name << endl;
    cout << "Pointer value " << *string_ptr << endl;

    return 0;
}