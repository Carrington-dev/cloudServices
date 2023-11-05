#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int j = 0;
mutex m;

void increase(){
    // m.lock();
    // cout << i << endl;
    // i++;
    // m.unlock();
    for (int i = 0; i < 30; i++)
    {
        /* code */
        cout << i << " ";
        if (i % 20 == 0){
            cout << endl;
        }
    }
    cout << endl;
    
}

int main(){
    thread t1(increase);
    thread t2(increase);

    t1.join();
    t2.join();
    // t2.join();

    // cout << i << endl;

    return 0;
}