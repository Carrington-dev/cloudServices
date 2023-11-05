#include <iostream>

using namespace std;

int main(){
    char* charectors;
    int number;
    cout << "Enter the numbe of items you want to store: ";
    cin >> number;
    charectors =  new char[number];
    for(int i = 0; i < number; i++){
        cout << "Enter item number " << i << " : ";
        char num;
        cin >> num;
        charectors[i] = num;
    }
    cout << endl;
    
    for(int i = 0; i < number; i++){
        cout <<  charectors[i] << ", ";
        // cout << endl;
    }
    cout << endl;

    return 0;
}