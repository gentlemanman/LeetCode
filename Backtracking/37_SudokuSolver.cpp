#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> &board, int i, int j){
    for(int col = 0; col < 9; ++col){
        if(j != col && board[i][j] == board[i][col]) return false;
    }
    for(int row = 0; row < 9; ++row){
        if(i != row && board[i][j] == board[row][j]) return false;
    }
    for(int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row){
        for(int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col){
            if((row != i || col != j) && board[i][j] == board[row][col]) return false;
        }
    }
    return true;
}
bool dfs(vector<vector<char>> &board, int i, int j){
    if(i == 9) return true;
    if(j >= 9) return dfs(board, i + 1, 0);
    if(board[i][j] == '.'){
        for(int k = 1; k <= 9; ++k){
            board[i][j] = (char)(k + '0');
            if(isValid(board, i, j) && dfs(board, i, j)) return true;
            board[i][j] = '.';
        }
    }
    else {
        return dfs(board, i, j + 1);
    }
    return false;
}
void solveSudoku(vector<vector<char>> &board){
    if(board.empty() || board.size() != 9 || board[0].size() != 9) return;
    dfs(board, 0, 0);
}

int main(){
    vector<vector<char> > board ={{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    return 0;
}

