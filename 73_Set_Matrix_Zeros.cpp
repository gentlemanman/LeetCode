#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void setZeroes(vector<vector<int> > &matrix){
        int len1 = matrix.size();
        int len2 = matrix[0].size();
        if(len1==0 || len2==0) return;
        int row = -1,col = -1;
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                if(matrix[i][j] == 0){
                    row = i;col=j;
                    break;
                }
            }
        }
        if(row == -1) return ;
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                if(matrix[i][j] == 0 && i != row && j != col){
                    matrix[i][col] = 0;
                    matrix[row][j] = 0;
                }
            }
        }
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                if(i != row && j != col){
                    if(matrix[i][col] == 0)
                        matrix[i][j] = 0;
                    else if(matrix[row][j] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
        int index = -1;
        while(++index < len1) matrix[index][col] = 0;
        index = -1;
        while(++index < len2) matrix[row][index] = 0;
        return ;
    } 
};
int main(){
    vector<vector<int> > v = {{1,1,2},{2,0,4},{1,2,3}};
    Solution s;
    s.setZeroes(v);
    for(int i=0; i<v.size(); ++i){
        for(int j=0; j<v[0].size(); ++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

