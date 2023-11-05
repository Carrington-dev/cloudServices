#include <iostream>

using namespace std;

class Node{
    public:
        int number;
        Node* next = nullptr;
        Node(int num): number(num){}
};

class MyList{
    public:
        Node* head = nullptr;
        MyList(){}
        MyList(int num): head(new Node(num)){}

        void insert(Node* ourHead, int num){
            if(head == nullptr){
                head = new Node(num);
                return;
            }
            if(ourHead->next == nullptr){
                ourHead->next = new Node(num);
                return;
            }
            insert(ourHead->next, num);
        }

        void insert(int num){
            insert(head, num);
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
    MyList* linked_list = new MyList();
    linked_list->insert(5);
    linked_list->insert(4);
    linked_list->insert(42);
    for(int i = 0; i < 23; i++){
        linked_list->insert(i);
    }
    linked_list->print();
    return 0;
}