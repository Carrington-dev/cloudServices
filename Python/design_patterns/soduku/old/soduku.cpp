#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> cols[9];
unordered_set<int> rows[9];
unordered_set<int> box[3][3];



bool check(int x, int r, int c) {
    return (cols[c].count(x) == 0) && (rows[r].count(x) == 0) 
        && (box[r/3][c/3].count(x) == 0);
}

    
    
    
bool dfs(vector<vector<char>>& board, int row, int col) {
    if (col == 9) {
        row ++;
        col = 0;
    }
    if (row == 9) {
        return true;
    }       
    if (board[row][col] != 0) {
        return dfs(board, row, col + 1);
    }
    for (int i = 1; i <= 9; ++ i) {
        if (check(i, row, col)) {
            board[row][col] = (char)(48 + i);
            cols[col].insert(i);
            rows[row].insert(i);
            box[row/3][col/3].insert(i);
            if (dfs(board, row, col + 1)) {                  
                return true;
            }
            board[row][col] = 0;
            cols[col].erase(i);
            rows[row].erase(i);       
            box[row/3][col/3].erase(i);
        }
    }
    return false;
}


void solveSudoku(vector<vector<char>>& board) {
    for (int r = 0; r < 9; ++ r) {
        for (int c = 0; c < 9; ++ c) {
            if (board[r][c] != '.') {
                int x = board[r][c] - '0';
                cols[c].insert(x);
                rows[r].insert(x);
                box[r/3][c/3].insert(x);
            }
        }
    }
    dfs(board, 0, 0);
}



void print(vector<vector<char>> &arr, int n)
{
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}




int main(){
  
    int n = 25;
    vector<vector<char>> new_arr;
    for (int i = 0; i < n; i++){
        vector<char> aa;
        for (int j = 0; j < n; j++){
            char num;
            cin >> num;
            aa.push_back(num);
        }
        new_arr.push_back(aa);
    }

    cout << endl;
    print(new_arr, n);
    cout << endl;
    solveSudoku(new_arr);
    cout << endl;
    print(new_arr, n);
    cout << endl;
    return 0;
}


/*
0 4 0 0 0 0 1 7 9
0 0 2 0 0 8 0 5 4
0 0 6 0 0 5 0 0 8
0 8 0 0 7 0 9 1 0
0 5 0 0 9 0 0 3 0
0 1 9 0 6 0 0 4 0
3 0 0 4 0 0 7 0 0
5 7 0 1 0 0 2 0 0
9 2 8 0 0 0 0 6 0
*/