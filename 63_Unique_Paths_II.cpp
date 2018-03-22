#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if( row == 0 || col == 0 ||obstacleGrid[0][0] == 1 || obstacleGrid[row-1][col-1] == 1){
            return 0;
        }
        vector<int> res(col,0);
        res[0] = 1;

        for(int i=0; i<row; ++i){
            if(obstacleGrid[i][0] == 1) 
                res[0] = 0;
            for(int j=1; j<col; ++j){
                if(obstacleGrid[i][j] == 0)
                    res[j] = res[j] + res[j-1];
                else 
                    res[j] = 0;
            }
        }

        return res[col-1];
    }
};

int main()
{
    vector<vector<int> > v={{0,0,0},{0,1,0},{0,0,0}};
    Solution s;
    cout<<s.uniquePathsWithObstacles(v)<<endl;
    return 0;
}
