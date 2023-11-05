#include <iostream>

using namespace std;

class Node{
    public:
        int number;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int num): number(num){}
        Node(){}
};


class BST{
    private:
        Node* head = nullptr;
    public:
        BST(){}

        Node* insert(Node* current, int num){
            if(current == nullptr){
                current =  new Node(num);
                if(head == nullptr) head = current;
                return current;
            }

            if( current->number < num){
                current->right = insert(current->right, num);
            }else{
                current->left = insert(current->left, num);
            }

            if(head == nullptr) head = current;

            return current;

        }



        void insert(int num){
            insert(head, num);
        }


        void printDataPreOrder(Node* current){
            if(current == nullptr){
                return;
            }
            // cout << head->number << endl;
            cout << current->number << " "; 
            printDataPreOrder(current->left);
            printDataPreOrder(current->right);
        }
        void printDataInOrder(Node* current){
            if(current == nullptr){
                return;
            }
            // cout << head->number << endl;
            printDataInOrder(current->left);
            cout << current->number << " "; 
            printDataInOrder(current->right);
        }
        void printDataPostOrder(Node* current){
            if(current == nullptr){
                return;
            }
            // cout << head->number << endl;
            printDataPostOrder(current->left);
            printDataPostOrder(current->right);
            cout << current->number << " "; 
        }
        void printDataPreOrder(){
            printDataPreOrder(head);
            cout << endl;
        }
        void printDataInOrder(){
            printDataInOrder(head);
            cout << endl;
        }
        void printDataPostOrder(){
            printDataPostOrder(head);
            cout << endl;
        }

        void print(){
            if(head != nullptr){
                cout << "head->number is " << head->number << endl;
            }else{
                cout << "head->number is empty" << endl;
            }
        }



};

int main(){
    BST* binary_tree = new BST();
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << endl;
    while(num != -1){
        cout << "\nEnter a number: ";
        binary_tree->insert(num);
        cin >> num;
        cout << endl;
    }
    binary_tree->print();
    binary_tree->printDataPreOrder();
    binary_tree->printDataInOrder();
    binary_tree->printDataPostOrder();

    return 0;
}