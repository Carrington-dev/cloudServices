#include <map>
#include <iostream>

using namespace std;

int main()
{
    map<int, string> numbers;
    numbers[1] = "one";
    numbers[2] = "two";
    numbers[3] = "three";
    numbers[4] = "four";

    for(auto key: numbers){
        cout << key.first << " -> " << key.second << endl;
    }

    return 0;
}