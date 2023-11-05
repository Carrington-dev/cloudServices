#include <map>
#include <iostream>

using namespace std;

int main(){
    map<int, int> dictionary;

    for(int i = 0; i < 10; i++){
        if(i % 2 == 0)
            dictionary[i] = (i*i + 1);
    }

    for(auto i: dictionary){
        cout << "i = " << i.first << " "
        << "(" << i.first <<"*2+1) = " << i.second << " " << endl;
    }


    cout  << endl;
    cout  << endl;

    for(auto i = 0; i < 10; i++){
        auto it = dictionary.lower_bound(i);
        auto ity = dictionary.upper_bound(i);
        cout << "i = " << i << " "
        << "lower_bound(" << i <<") = " << (*it).first << " " 
        << "lower_bound(" << i <<") = " << (*it).second << " " 
        << "upper_bound(" << i <<") = " << (*ity).first << " " 
        << "upper_bound(" << i <<") = " << (*ity).second << " " 
        << endl;
    }
    return 0;
}