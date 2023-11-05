#include <iostream>

using namespace std;

void print(void* ptr, char type){
    switch (type){
        case 'i':
            cout << *((int*)ptr) << endl;
            break;
        case 'f':
            cout << *((float*)ptr) << endl;
            break;
        case 'd':
            cout << *((double*)ptr) << endl;
            break;
        case 'c':
            cout << *((char*)ptr) << endl;
            break;
        case 's':
            cout << *((string*)ptr) << endl;
            break;
        default:
            cout << *((char*)ptr) << endl;
            break;
    }
}


int main(){
    string name_ptr = "Carrington";
    print(&name_ptr, 's');
    return 0;
}