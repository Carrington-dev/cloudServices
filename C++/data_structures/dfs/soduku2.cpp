#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

void solve(vector<vector<int>> &arr)
{
    stack<pair<int, int>> myIdentifier;
    set<pair<int, int>> myNumbers;

    myIdentifier.push(make_pair(0, 0));

    while(!myIdentifier.empty()){

    }

}


pair<int, int>& moveNext(int i, int j, int n){

}

void print(vector<vector<int>> &arr, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> new_arr;
    for (int i = 0; i < n; i++){
        vector<int> aa;
        for (int j = 0; j < n; j++){
            int num;
            cin >> num;
            aa.push_back(num);
        }
        new_arr.push_back(aa);
    }

    cout << endl;
    solve(new_arr);
    print(new_arr, n);
    
    return 0;
}