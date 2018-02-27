#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    int totalNQueens(int n){
        int res=0;
        vector<int> pos(n, -1);
        solveNQueensDFS(pos, 0, res);
        return res;
    }
    void solveNQueensDFS(vector<int> &pos, int row, int &res){
        int n = pos.size();
        if(row == n){
            ++res;
        }else{
            for(int col=0; col<n; ++col){
                if(isValid(pos, row, col)){
                    pos[row]=col;
                    solveNQueensDFS(pos, row+1, res);
                    pos[row]=-1;
                }
            }
        }
    }
    bool isValid(vector<int> &pos, int row, int col){
        for(int i=0; i<row; ++i){
            if(col == pos[i] || abs(row-i) == abs(col-pos[i])){
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.totalNQueens(4);
    return 0;
}
