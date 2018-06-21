#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    bool exist(vector<vector<char> >& board, string word){
        int row = board.size();
        int col = board[0].size();
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for(int i=0; i<row; ++i)
            for(int j=0; j<col; ++j)
                if(dfs(board,visited,i,j,0,word))
                    return true;
        return false;
    }
    bool dfs(vector<vector<char> >& board, vector<vector<bool> >visited, int row, int col, int idx, string word){
        if(word.length() == idx){
            return true;
        }
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size()) return false;
        char ch = word[idx];
        if(!visited[row][col] && ch==board[row][col]){
            visited[row][col] = true;
            bool res = dfs(board, visited, row-1, col, idx+1, word) ||
                       dfs(board, visited, row+1, col, idx+1, word) ||
                       dfs(board, visited, row, col-1, idx+1, word) ||
                       dfs(board, visited, row, col+1, idx+1, word);
            visited[row][col] = false;
            return res;
        }
        return false;
    }
};


