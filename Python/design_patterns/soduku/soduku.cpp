#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isSafe(int numberBeingTested, int row, int col,  vector<vector<int>> & old_array);
bool depthFirstSearch(int row, int col,  vector<vector<int>> & old_array);
int bfs(int& row, int& col,  vector<vector<int>> & old_array);
bool solveSodukuFinal(vector<vector<int>> & old_array);
void changePoint(int& x, int& y, vector<vector<int>> old_array);
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
    int n = 9;
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
    print(new_arr, n);
    cout << endl;
    if(solveSodukuFinal(new_arr)){
        print(new_arr, n);
    }else{
        cout << "No solution to the problem";
    }
    cout << endl;
    cout << endl;
    print(new_arr, n);
    return 0;
}

bool solveSodukuFinal(vector<vector<int>> & old_array){
    stack<pair<int, int>> num;
    num.emplace(make_pair(0, 0));
    int row = 0, col = 0;
    bool isSolved = false;
    while(!num.empty() && (row = (int) old_array.size()) && (col = (int) old_array.size())){
        pair<int, int> top = num.top();
        int row = top.first;
        int col = top.second;
        int f = bfs(row, col, old_array);
        if(f != 0){
            old_array[row][col] = f;
            num.emplace(make_pair(row, col));
        }
    }
    return isSolved;
}

int bfs(int& row, int& col,  vector<vector<int>> & old_array){
    // bool isReallySafe = false;
    for(int i = 1; i <= (int) old_array.size(); i++)
    {
        if(isSafe( i, row, col, old_array)){
            return i;
        }
    }    
    return 0;
}


void changePoint(int& x, int& y, vector<vector<int>> old_array){
    if(x < (int) old_array.size()){
        x++;
    }else{
        if(y < (int) old_array.size()){
            y++;
        }else{
            return;
        }
    }
    return;
}

bool isSafe(int numberBeingTested, int row, int col,  vector<vector<int>> & old_array){
    for(int i = 0; i <  (int) old_array.size(); i++){
        if( numberBeingTested == old_array[row][i]){
            return false;
        }
        if( numberBeingTested == old_array[i][col]){
            return false;
        }
    }
    int rowSection = (row / sqrt(  (int) old_array.size())) ;
    int colSection = (col / sqrt(  (int) old_array.size())) ;
    int rowSectionUpper = row + (int) sqrt(old_array.size());
    int colSectionUpper = col + (int) sqrt(old_array.size());
    // int rowSectionUpper = ceil(row / sqrt(old_array.size())) ;
    // int colSectionUpper = ceil(col / sqrt(old_array.size())) ;
    for(int i = rowSection; i < rowSectionUpper; i++ ){
        for(int j = colSection; j < colSectionUpper; j++ ){
            if( old_array[i][j] == numberBeingTested ){
                return false;
            }
        }
    }

    return true;
}

