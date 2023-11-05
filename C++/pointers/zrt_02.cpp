#include <iostream>

using namespace std;


int main(){

    // int numbers[] = {0, 7, 3, 2, 9};
    // cout << numbers << endl;
    // cout << numbers[0] << endl;
    // cout << *numbers << endl;

    int* numbers;
    int numberOfItems;
    cout << "Enter the number of items you want to store : ";
    cin >> numberOfItems;
    numbers = new int[numberOfItems];
    for(int i = 0; i < numberOfItems; i++){
        int a;
        cout << "Enter item number " << i << " ";
        
        cin >> a;
        numbers[i] = a;
    }

    for(auto i = 0; i < numberOfItems; i++){
        cout << numbers[i] << " ";
    }
    
    cout << endl;
    
    
    return 0;
}