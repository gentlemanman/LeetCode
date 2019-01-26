//
// Created by Administrator on 2019/1/13.
//
#include <bits/stdc++.h>
using namespace std;
bool search(vector<vector<char>>& board, string word, int idx, int i, int j){
    if(idx == word.size()) return true;
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx]) return false;
    char tmp = board[i][j];
    board[i][j] = '#'; // 找过的先设置成#然后再恢复
    bool res = search(board, word, idx + 1, i - 1, j) ||
                search(board, word, idx + 1, i + 1, j) ||
                search(board, word, idx + 1, i, j - 1) ||
                search(board, word, idx + 1, i, j + 1);
    board[i][j] = tmp;
    return res;

}

bool exist(vector<vector<char>>& board, string word){
    if(board.empty()) return false;
    int m = (int)board.size(), n = (int)board[0].size();
    for(int i = 0; i < m ; ++i){
        for(int j = 0; j < n; ++j){
            if(search(board, word, 0, i, j)) return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
            {'A', 'B', 'C', 'E'},
            {'S', 'F', 'C', 'S'},
            {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout<<exist(board, word)<<endl;
    return 0;
}