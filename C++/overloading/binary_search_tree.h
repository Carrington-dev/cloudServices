class BST{
    public:
        int length = 0;
        int size = 0;

        class Node {
            public:
                int number;
                Node* left;
                Node* right;
                Node(int num): number(num){ 
                    right = nullptr; 
                    left = nullptr; 
                }
        };

        Node* head;
        

        BST(){
            head = nullptr;
        }


        void insert(Node* root, int number){
            length += 1;
            if( root == nullptr ) { 
                root = new Node( number );
                return;
            }
            if( root->number > number){
                
            }
        }

        void insert(int number){
            insert(head, number);
        }

        void insert(){

        }
};