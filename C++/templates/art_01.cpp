#include <iostream>
#include <vector>

using namespace std;

template<typename T>

vector<T> generateListOfTerms(int n, string type){
    vector<T> v;
    if(type == "string"){
        for(int i = 0; i < n; i++){
                v.push_back("string");
        }
    }
    // if(type == "char"){
    //     for(int i = 0; i < n; i++){
    //             v.push_back((char)(i+65));
    //     }
    // }
    if(type == "int"){
        for(int i = 0; i < n; i++){
                v.push_back(i+65);
        }
    }
    return v;
}

template<typename T>
void swapping(T& a, T& b){
    cout << "a = " << a << " b = " << b << endl;
    T temp = b;
    b = a;
    a = temp;
    cout << "a = " << a << " b = " << b << endl;
}

template<typename T>


void addRandom(T& a, T& b){
    cout << "a = " << a << " b = " << b << endl;
    T temp = b;
    b = a;
    a = temp;
    cout << "a = " << a << " b = " << b << endl;
}

int main(){
    vector<int> a = generateListOfTerms<int>( 9, "int");
    for(size_t i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl;
    // int a = 8, b = 9;
    // swapping(a, b);
    // char aa = 'C', bb = 'A';
    // swapping(aa, bb);
    // string aaa = "Carrington", bbb = "Muleya";
    // addRandom(aaa, bbb);

    return 0;
}