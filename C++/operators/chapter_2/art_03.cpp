#include <iostream>

using namespace std;

class PowerList{
    private:
        int* myList;
        int size = 0, num_allocated = 1;

    public:
        PowerList(int number): myList(new int[number]){
            num_allocated = number;
            size = 0;
        }
        PowerList(){
            size = 0;
        }
        ~PowerList(){
            cout << "deleting items in the powerlist" << endl;
            delete[] myList;
        }

        void print_list(){
            // size  = 2;
            cout << "[";
            for(int i = 0; i < getSize(); i++){
                if(i != getSize() - 1){
                    cout << myList[i] << ", " ;
                }else{
                    cout << myList[i] << "" ;
                }
            }
            cout << "]"<< endl;
        }

        void push_back(int item){
            // print_list();
            if( size < num_allocated){
                myList[size] = item;
            }else{
                num_allocated = 2 * num_allocated;
                int* new_arr = new int[num_allocated];
                for (int i = 0; i < size; i++)
                {
                    new_arr[i] = myList[i];
                }
                delete[] myList;
                new_arr[size] = item;
                myList = new_arr;
                
            }
            size++;
            // print_list();

        }

        int pop_back(){
            if( size > 0){
                int a =  myList[ size - 1];
                myList[ size - 1] = int(NULL);
                size -= 1;
                return a;
            }
        }

        int& operator[](int position){
            if(position < num_allocated && position >= 0){
                return myList[position];
            }else{
                throw std::out_of_range( "Index out of bounds");
                exit(0);
            }
        }
        int getSize(){
            return size;
        }

         

};

int main(){
    PowerList myArray(12);
    myArray.print_list();
    for(int i = 0; i < 29; i++){
        myArray.push_back(i);
    }
    myArray.print_list();
    for(int i = 0; i < myArray.getSize(); i++){
        cout << "poped at: " << myArray.pop_back() << endl;
        myArray.print_list();
    }


    return 0;
}