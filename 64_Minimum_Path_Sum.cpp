#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minPathSum(vector<vector<int> >& grid){
        int m = grid.size();
        int n = grid[0].size();
        if(m==0 || n==0) return 0;
        vector<int> res(n,0);
        res[0] = grid[0][0];
        for(int i=1; i<n; ++i)
            res[i]=grid[0][i] + res[i-1];
        cout<<res[0]<<res[1]<<res[2]<<endl;
        for(int i=1; i<m; i++){
            res[0] = res[0] + grid[i][0];
            for(int j=1; j<n; j++){
                res[j] = min(res[j],res[j-1]) + grid[i][j];
            }
        }
        return res[n-1];
    }
};

int main(){
    vector<vector<int> > v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution s;
    cout<<s.minPathSum(v)<<endl;
    return 0;
}
