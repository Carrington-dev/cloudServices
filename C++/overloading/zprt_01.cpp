#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    BST* binary_search_tree = new BST();
    binary_search_tree->insert(786);
    binary_search_tree->insert(897);

    int numbers[] = { 78, 89, 76, 45, 77, 88, 90,  34 };
    cout << binary_search_tree->length << endl;
    cout << sizeof(binary_search_tree) << endl;
    cout << (( nullptr == NULL ) == (false)) << endl;
}