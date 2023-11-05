#include <iostream>

using namespace std;

class Node{
    public:
        int number;
        Node* next = nullptr;
        Node(int num): number(num){}
};

class LinkedList{
    public:
    
        Node* head = nullptr;

        LinkedList(){}

        void insert(int num, Node* myHead){
            if(head == nullptr){
                head = new Node(num);
            }
            if(myHead->next == nullptr ){
                myHead->next = new Node(num);
                return;
            }
            insert(num, myHead->next);
        }

        void insert(int num){
            insert(num);
        }

        void print(Node* current){
            if(current == nullptr){
                return;
            }
            cout << current->number << " ";
            print(current->next);
        }

        void print(){
            print(head);
        }
};

int main(){
    LinkedList* myList = new LinkedList();
    for(int i = 0; i < 23; i++){
        myList->insert(i);
    }

    myList->print();

}