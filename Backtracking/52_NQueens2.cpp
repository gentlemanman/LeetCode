#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& pos, int row, int col){
    for(int i = 0; i < row; ++i){
        if(pos[i] == col || abs(pos[i] - col) == abs(i - row)) return false;
    }
    return true;
}

void dfs(int &count, int row, vector<int> &pos){
    int n = (int)pos.size();
    if(row == n){
        count++;
        return;
    }
    else{
        for(int col = 0; col < n; ++col){
            if(isValid(pos, row, col)){
                pos[row] = col;
                dfs(count, row + 1, pos);
                pos[row] = -1;
            }
        }
    }
}

int totalNQueens(int n){
    if(n <= 0) return 0;
    int count = 0;
    vector<int> pos(n, -1);
    dfs(count, 0, pos);
    return count;
}

int main(){
    int r = totalNQueens(4);
    cout<<r<<endl;
    return 0;
}