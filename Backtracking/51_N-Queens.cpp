#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &pos, int row, int col){
    for(int i = 0; i < row; ++i){
        if(pos[i] == col || abs(pos[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void dfs(vector<vector<string>> &ans, int row, vector<int> &pos){
    int n = (int)pos.size();
    if(row == n){
        vector<string> tmp(n, string(n, '.'));
        for(int i = 0; i < n; i++){
            tmp[i][pos[i]] = 'Q';
        }
        ans.push_back(tmp);
    }
    else{
        for(int col = 0; col < n; ++col){
            if(isValid(pos, row, col)){
                pos[row] = col;
                dfs(ans, row + 1, pos);
                pos[row] = -1;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    if(n <= 0) return ans;
    vector<int> pos(n, -1); // p[i]:第i行皇后的位置
    dfs(ans, 0, pos);
    return ans;
}

int main(){
    vector<vector<string>> ans = solveNQueens(3);

    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[0].size(); ++j){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
    cout<<ans.size()<<endl;
    return 0;
}