#include <iostream>

using namespace std;

class LinkedList{
    class Node{
        public:
            int item;
            Node* next = nullptr;
            Node(int num): item(num){}
    };

    public:
        Node* head;
        LinkedList(){ head = nullptr;}

        void insert(int num){

            if( head ==  nullptr)
            {
                head =  new Node(num);
                return;
            }

            Node* current = head;
            while( current->next != nullptr ){
                current =  current->next;
            }
            current->next = new Node(num);

        }

        void print(){
            Node* current = head;
            while( current != nullptr ){
                cout << current->item << " ";
                current =  current->next;
            }
            cout << endl;
        }

        LinkedList* joinList(LinkedList* li1, LinkedList* li2)
        {
            LinkedList* newList = new LinkedList();
            Node* current1 =  head;
            Node* current2 =  li2->head;

            while( current1 != nullptr && current2 != nullptr)
            {
                if( current1->item > current2->item){
                    newList->insert(current2->item);
                    current2 = current2->next;
                }else{
                    newList->insert(current1->item);
                    current1 = current1->next;
                }
            }

            while( current1 != nullptr)
            {
                newList->insert(current1->item);
                current1 = current1->next;
            }

            while( current2 != nullptr)
            {
                newList->insert(current2->item);
                current2 = current2->next;
            }


            return newList;
        }
};


int main(){
    LinkedList* list = new LinkedList();
    LinkedList* list_2 = new LinkedList();
    
    for(int i = 0; i < 25; i+=2)
    {
        list->insert(2 + i);
    }
    for(int i = 1; i < 26; i+=2)
    {
        list_2->insert(2 + i);
    }

    list->print();
    list_2->print();
    LinkedList* list_3 = list->joinList(list, list_2);
    list_3->print();
    return 0;
}