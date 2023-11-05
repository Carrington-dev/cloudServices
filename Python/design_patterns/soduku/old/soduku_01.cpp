#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <cmath>

using namespace std;

bool isSafe(int numberBeingTested, int row, int col,  vector<vector<int>> & old_array);
bool depthFirstSearch(int row, int col,  vector<vector<int>> & old_array);
void print(vector<vector<int>> &arr, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveSodukuFinal(vector<vector<int>> & old_array);

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
    for(int i = 0; i <  (int) old_array.size(); i++ ){
        for(int j = 0; j <  (int) old_array.size(); j++ ){
            depthFirstSearch(i, j, old_array);
        }
    }
    return false;
}

bool depthFirstSearch(int row, int col,  vector<vector<int>> & old_array){
    if(row == (int) old_array.size()){
        return true;
    }
    if(col ==  (int) old_array.size()){
        row += 1;
        col = 0;
    }
    stack<pair<int, int>> all;
    if(all.empty()){
        all.emplace(make_pair(0, 0));
    }
    
    return false;
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

