#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

int sum_Odd = 0;
int sum_Even = 0;
mutex m;

int sumEven(int start, int end){
    m.lock();
    int sum = 0;
    for (int i = start; i < end; i++){
        if( i % 2 == 0){
            sum_Even += i;
        }
    }
    m.unlock();
    return sum_Even;
}
int sumOdd(int start, int end){
    m.lock();
    int sum = 0;
    for (int i = start; i < end; i++){
        if( i % 2 == 1){
            sum_Odd += i;
        }
    }
    m.unlock();
    return sum_Odd;
}

int main(){
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<float> fsec;
    int start = 0, end = 1900000;
    auto time_now = clock::now();

    thread t1(sumEven, start, end);
    thread t2(sumOdd, start, end);

    t1.join();
    t2.join();


    // cout << "sumEven = " << sumEven(start, end) << endl;
    // cout << "sumOdd = " << sumEven(start, end) << endl;
    cout << "sumEven = " << sum_Even << endl;
    cout << "sumOdd = " << sum_Odd << endl;

    auto time_later = clock::now();
    auto duration = (time_later -  time_now);
    // auto duration = duration_cast<milliseconds>(time_later -  time_now);
    ;
    cout << "time_Elapsed = " << duration.count() / 1000 << endl;



    return 0;
}